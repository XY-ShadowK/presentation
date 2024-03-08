#include "pch.h"
#include "framework.h"
#include "Transform.hpp"

TransformMatrix::TransformMatrix()/* : matrixTranslate{ {1,0,0},{0,1,0},{0,0,1} }*/
{

}

TransformMatrix::~TransformMatrix()
{

}

CPoint TransformMatrix::translate(CPoint pointOrigin, double deltaX, double deltaY)
{
	return encapsulateCP(pointOrigin.x + deltaX, pointOrigin.y + deltaY);
}

CPoint TransformMatrix::scale(CPoint pointOrigin, double scaleX, double scaleY)
{
	return encapsulateCP(pointOrigin.x * scaleX, pointOrigin.y * scaleY);
}

CPoint TransformMatrix::rotateR(CPoint pointOrigin, double radian)
{
	double sinR = sin(radian), cosR = cos(radian);
	return encapsulateCP(pointOrigin.x * cosR - pointOrigin.y * sinR, pointOrigin.x * sinR + pointOrigin.y * cosR);
}

CPoint TransformMatrix::rotateA(CPoint pointOrigin, double angle)
{
	return rotateR(pointOrigin, angleToRadian(angle));
}

CPoint TransformMatrix::reflectO(CPoint pointOrigin)
{
	return scale(pointOrigin, -1, -1);
}

CPoint TransformMatrix::reflectX(CPoint pointOrigin)
{
	return scale(pointOrigin, 1, -1);
}

CPoint TransformMatrix::reflectY(CPoint pointOrigin)
{
	return scale(pointOrigin, -1, 1);
}

CPoint TransformMatrix::shear(CPoint pointOrigin, double b, double c)
{
	return encapsulateCP(pointOrigin.x + c * pointOrigin.y, b * pointOrigin.x + pointOrigin.y);
}

double TransformMatrix::angleToRadian(double angle)
{
	return angle * PI / 180.00;
}

CPoint TransformMatrix::encapsulateCP(double xCP, double yCP)
{
	return CPoint((int)round(xCP), (int)round(yCP));
}

CPoint TransformVertex(CPoint pointOrigin,double* matrixTrans)
{
	double xP = pointOrigin.x, yP = pointOrigin.y,wPT;
	int xPT, yPT;
	wPT = xP * *(matrixTrans + 2) + yP * *(matrixTrans + 5) + *(matrixTrans + 8);
	xPT = (int)round((xP * *matrixTrans + yP * *(matrixTrans + 3) + *(matrixTrans + 6)) / wPT);
	yPT = (int)round((xP * *(matrixTrans + 1) + yP * *(matrixTrans + 4) + *(matrixTrans + 7)) / wPT);
	return CPoint(xPT, yPT);
}