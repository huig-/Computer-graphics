#pragma once
#include <GL/freeglut.h>
#include "Cubo.h"

class Coche
{
public:
	Coche();
	~Coche();
	void dibuja(GLUquadricObj* q, double lCubo, double rRueda);
private:
	Cubo* c;
	void dibujaRueda(double rRueda, GLUquadricObj* q, double anchuraRueda);
	void dibujaChasis();
};

