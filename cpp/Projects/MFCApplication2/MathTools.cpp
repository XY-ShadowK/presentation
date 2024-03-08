#include "pch.h"
#include "MathTools.h"

double MathTools::toPrecision(LL t)
{
	return (double)t / PRECISION;
}

MathTools::MathTools()
{
	int num = MAX_N_FAC;
	fac.resize(num + 1);
	fac[0] = 1;
	for (int i = 1; i <= num; i++)
		fac[i] = fac[i - 1] * i;
	std::vector<std::vector<double>> pow_ti;
	std::vector<double> pow_t;
	pow_t.resize(PRECISION + 1);
	pow_ti.resize(num + 1, pow_t);
	pow_nit.resize(num + 1, pow_ti);
	isPowSet.resize(num + 1, false);
}

void MathTools::setPow(LL n)
{
	for (LL i = 0; i <= n; i++)
		for (LL t = 0; t <= PRECISION; t++)
			this->pow_nit[n][i][t] = pow(toPrecision(t), i) * pow(1 - toPrecision(t), n - i);
}

MathTools::LL MathTools::getComposite(LL n, LL m)
{
	m = min(m, n - m);
	return this->fac[n] / this->fac[m] / this->fac[n - m];
}

double MathTools::getPow(LL n, LL i, LL t)
{
	if (!this->isPowSet[n])
		this->setPow(n);
	return this->pow_nit[n][i][t];
}

double MathTools::getBernstein(LL n, LL i, LL t)
{
	return (double)this->getComposite(n, i) * this->getPow(n, i, t);
}