#pragma once
class MVector
{
protected:
	std::vector<double> mathV;
	bool isError;
public:
	MVector();
	MVector(std::vector<double> v);
	MVector(bool error);
	double unitalize();
	double dotProduct(const MVector& v);
	friend MVector operator+(const MVector& v1, const MVector& v2);
	friend MVector operator-(const MVector& v1, const MVector& v2);
	friend MVector operator*(const MVector& v1, const MVector& v2);
	friend MVector operator*(const double& d, const MVector& v1);
	friend MVector operator/(const MVector& v1, const MVector& v2);
	friend MVector operator/(const MVector& v1, const double& d);
};

class MRGB : public MVector
{
public:
	MRGB() = default;
	MRGB(MVector mvector);
	MRGB(double r, double g, double b);
	void normalize();
	COLORREF getColor();
};

class MLight;
class MMaterial
{
protected:
	MRGB kA;
	MRGB kD;
	MRGB kS;
	double specularN;
public:
	MMaterial() = default;
	MMaterial(MRGB a, MRGB d, MRGB s, double n);
	MRGB getKA();
	friend MRGB getLightShader(MLight light, MMaterial material, MVector loc, MVector vV, MVector vN);
};

class MLight
{
protected:
	MRGB iMD;
	MRGB iMS;
	MVector coordinate;
	double C0;
	double C1;
	double C2;
public:
	MLight() = default;
	MLight(MRGB d, MRGB s, MVector c, double c0, double c1, double c2);
	double getFade(double dist);
	friend MRGB getLightShader(MLight light, MMaterial material, MVector loc, MVector vV, MVector vN);
};