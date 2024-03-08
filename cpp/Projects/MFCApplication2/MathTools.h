#pragma once
class MathTools
{
public:
	using LL = long long;
	static const int MAX_N_FAC = 20;
	static constexpr double PRECISION = 100.00;
	static double toPrecision(LL t);
private:
	std::vector<LL> fac;
	std::vector<std::vector<std::vector<double>>> pow_nit;
	std::vector<bool> isPowSet;
public:
	MathTools();
	void setPow(LL n);
	LL getComposite(LL n, LL m);
	double getPow(LL n,LL i,LL t);
	double getBernstein(LL n, LL i, LL t);
};