#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_
#pragma once

class TransformMatrix {
private:
	//double matrixTranslate[3][3];
	//double matrixScale[3][3];
	//double matrixRotate[3][3];
	//double matrixReflect[3][3];
	//double matrixShear[3][3];
	static constexpr double PI = 3.1415926;
public:
	TransformMatrix();
	~TransformMatrix();
	static CPoint translate(CPoint pointOrigin, double deltaX, double deltaY);
	static CPoint scale(CPoint pointOrigin, double scaleX, double scaleY);
	static CPoint rotateR(CPoint pointOrigin, double radian);
	static CPoint rotateA(CPoint pointOrigin, double angle);
	static CPoint reflectO(CPoint pointOrigin);
	static CPoint reflectX(CPoint pointOrigin);
	static CPoint reflectY(CPoint pointOrigin);
	static CPoint shear(CPoint pointOrigin, double b, double c);
	static double angleToRadian(double angle);
	static CPoint encapsulateCP(double xCP, double yCP);
};

CPoint TransformVertex(CPoint pointOrigin,double* matrixTrans);

#endif // !_TRANSFORM_HPP_
