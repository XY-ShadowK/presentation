#include "pch.h"
#include "LucasComposite.h"

LucasComposite::LucasComposite(int num)
{
	fac = new LL[num + 1];
	inv = new LL[num + 1];
	invFac = new LL[num + 1];
	fac[0] = 1;
	inv[0] = 1;
	inv[1] = 1;
	p = sC.getComposite(num, num / 2);
	for (int i = 1; i <= num; i++)
		fac[i] = fac[i - 1] * i % p;

}

constexpr LucasComposite::Composite::Composite()
{
	setFac();
}

LucasComposite::Composite::~Composite()
{
	delete this->fac;
	this->fac = NULL;
}

void LucasComposite::Composite::setFac()
{
	int num = MAX_N_FAC;
	fac = new LL[num + 1];
	fac[0] = 1;
	for (int i = 1; i <= num; i++)
		fac[i] = fac[i - 1] * i;
}

LucasComposite::LL LucasComposite::Composite::getComposite(LucasComposite::LL n, LucasComposite::LL m)
{
	m = min(m, n - m);
	return this->fac[n] / this->fac[m] / this->fac[n - m];
	//LL dividend = n - m + 1, divisor = 1;
	//dividend = dividend > n ? 1 : dividend;
	//for (LL i = 2; i <= m; i++)
	//	divisor *= i;
	//for (LL i = n - m + 2; i <= n; i++)
	//	dividend *= i;
	//return dividend / divisor;
}