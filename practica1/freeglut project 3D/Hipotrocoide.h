#pragma once
#include "Malla.h"
class Hipotrocoide :
	public Malla
{
protected:
	double a;
	double b;
	double c;
	GLfloat M[16];
public:
	Hipotrocoide(int nP, int nQ);
	~Hipotrocoide();
private:
	PuntoVector3D* calculaT(double t);
	PuntoVector3D* calculaN(double t);
	PuntoVector3D* calculaB(double t);
	PuntoVector3D* calculaC(double t);
	void construyeM(double t);
};

