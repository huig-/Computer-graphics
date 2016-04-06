#pragma once
#include <GL/freeglut.h>
#include "Cubo.h"

class Coche
{
public:
	Coche();
	~Coche();
	void dibuja(GLUquadricObj* q);
private:
	Cubo* c;
	double lCubo;
	double rRueda;
	double anchuraRueda;
	double rFaro;
	double anchuraFaro;
	void dibujaRueda(GLUquadricObj* q);
	void dibujaChasis();
	void dibujaLuces(GLUquadricObj* q);
};

