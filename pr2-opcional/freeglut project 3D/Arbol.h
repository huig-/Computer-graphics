#pragma once
#include <GL/freeglut.h>
#include <math.h>

class Arbol
{
public:
	Arbol();
	~Arbol();
	void abeto(GLUquadricObj* q, double baseTronco, double baseCopa, double hTronco, double hCopa);
	void pino(GLUquadricObj* q, double baseTronco, double baseCopa, double hTronco, double hCopa);
	void roble(GLUquadricObj* q, double baseTronco, double hTronco, double radioCopa);
	void alamo(GLUquadricObj* q, double baseTronco, double hTronco, double radioCopa1, double radioCopa2);
};

