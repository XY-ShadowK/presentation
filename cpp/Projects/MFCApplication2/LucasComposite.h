#pragma once
class LucasComposite
{
public:
	using LL = long long;
	static const int MAX_N_FAC = 20;
	class Composite;
	static Composite sC;
private:
	LL* fac;
	LL* inv;
	LL* invFac;
	LL p;
public:
	LucasComposite(int num);
	~LucasComposite();
	LL Cnm(LL n, LL m);
};

class LucasComposite::Composite
{
public:
	static const int MAX_N_FAC = LucasComposite::MAX_N_FAC;
private:
	LL* fac;
public:
	Composite();
	~Composite();
	void setFac();
	LL getComposite(LL n, LL m);
};