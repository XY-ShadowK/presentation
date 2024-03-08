#include "pch.h"
#include "MVector.h"

using std::vector;

MVector::MVector()
{
	isError = false;
}

MVector::MVector(vector<double> v)
{
	mathV = v;
	isError = false;
}

MVector::MVector(bool error)
{
	isError = error;
}

double MVector::unitalize()
{
	double v = 0.0;
	for (auto it : this->mathV)
		v += it * it;
	v = sqrt(v);
	for (auto& it : this->mathV)
		it = it / v;
	return v;
}

double MVector::dotProduct(const MVector& v)
{
	MVector res = (*this) * v;
	if (res.isError)
		throw "MVector Error!";
	double d=0.0;
	for(auto it : res.mathV)
		d += it;
	return d;
}

MVector operator+(const MVector& v1, const MVector& v2)
{
	size_t size1 = v1.mathV.size(), size2 = v2.mathV.size();
	if (size1 != size2)
		return MVector(false);
	vector<double> v(size1, 0.0);
	for (size_t sz = 0; sz < size1; sz++)
		v[sz] = v1.mathV[sz] + v2.mathV[sz];
	return MVector(v);
}

MVector operator-(const MVector& v1, const MVector& v2)
{
	size_t size1 = v1.mathV.size(), size2 = v2.mathV.size();
	if (size1 != size2)
		return MVector(false);
	vector<double> v(size1, 0.0);
	for (size_t sz = 0; sz < size1; sz++)
		v[sz] = v1.mathV[sz] - v2.mathV[sz];
	return MVector(v);
}

MVector operator*(const MVector& v1, const MVector& v2)
{
	size_t size1 = v1.mathV.size(), size2 = v2.mathV.size();
	if (size1 != size2)
		return MVector(false);
	vector<double> v(size1, 0.0);
	for (size_t sz = 0; sz < size1; sz++)
		v[sz] = v1.mathV[sz] * v2.mathV[sz];
	return MVector(v);
}

MVector operator*(const double& d, const MVector& v1)
{
	size_t size1 = v1.mathV.size();
	vector<double> v(size1, 0.0);
	for (size_t sz = 0; sz < size1; sz++)
		v[sz] = v1.mathV[sz] * d;
	return MVector(v);
}

MVector operator/(const MVector& v1, const MVector& v2)
{
	size_t size1 = v1.mathV.size(), size2 = v2.mathV.size();
	if (size1 != size2)
		return MVector(false);
	vector<double> v(size1, 0.0);
	for (size_t sz = 0; sz < size1; sz++)
		v[sz] = v1.mathV[sz] / v2.mathV[sz];
	return MVector(v);
}

MVector operator/(const MVector& v1, const double& d)
{
	size_t size1 = v1.mathV.size();
	vector<double> v(size1, 0.0);
	for (size_t sz = 0; sz < size1; sz++)
		v[sz] = v1.mathV[sz] / d;
	return MVector(v);
}

MRGB::MRGB(MVector mvector)
{
	MVector* pMVector = &mvector;
	MRGB* mrgb = static_cast<MRGB*>(pMVector);
	mathV = mrgb->mathV;
	isError = mrgb->isError;
}

MRGB::MRGB(double r, double g, double b)
{
	mathV = vector<double>{ r,g,b };
	isError = false;
}

void MRGB::normalize()
{
	//size_t size = this->mathV.size();
	//double value;
	//for (size_t sz = 0; sz < size; sz++) {
	//	value = this->mathV[sz];
	//	this->mathV[sz] = value > 1.0 ? 1.0 : (value < 0.0 ? 0.0 : value);
	//}
	for (auto& it : this->mathV)
		it = it > 1.0 ? 1.0 : (it < 0.0 ? 0.0 : it);
}

COLORREF MRGB::getColor()
{
	TRACE("%lf,%lf,%lf", this->mathV[0], this->mathV[1], this->mathV[2]);
	this->normalize();
	MRGB color = 255 * (*this);
	return RGB(color.mathV[0], color.mathV[1], color.mathV[2]);
}

MMaterial::MMaterial(MRGB a, MRGB d, MRGB s, double n)
{
	kA = a;
	kD = d;
	kS = s;
	specularN = n;
}

MRGB MMaterial::getKA()
{
	return this->kA;
}

MLight::MLight(MRGB d, MRGB s, MVector c, double c0, double c1, double c2)
{
	iMD = d;
	iMS = s;
	coordinate = c;
	C0 = c0;
	C1 = c1;
	C2 = c2;
}

double MLight::getFade(double dist)
{
	return min(1, 1 / (this->C0 + (this->C1 + this->C2 * dist) * dist));
}

MRGB getLightShader(MLight light, MMaterial material, MVector loc, MVector vV, MVector vN)
{
	MVector vL = light.coordinate - loc,vH;
	double dist = vL.unitalize();
	vH = vL + vV;
	vH.unitalize();
	MRGB rgbloc = loc;
	rgbloc.getColor();
	return light.getFade(dist) * (max(vL.dotProduct(vN), 0) * material.kD * light.iMD + pow(max(vH.dotProduct(vN), 0), material.specularN) * material.kS * light.iMS);
}