#pragma once
#include <GL/freeglut.h>
#include "Cubo.h"

class Coche
{
public:
	Coche();
	~Coche();
	void dibuja(GLUquadricObj* q);
	void avanza(double inc);
private:
	Cubo* c;
	double lCubo;
	double rRueda;
	double anchuraRueda;
	double rFaro;
	double anchuraFaro;
	double posicionInicial;
	double anguloInicial;
	void dibujaRueda(GLUquadricObj* q);
	void dibujaChasis();
	void dibujaLuces(GLUquadricObj* q);
};

