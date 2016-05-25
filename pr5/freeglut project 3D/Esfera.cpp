#include "Esfera.h"


Esfera::Esfera(GLdouble radio)
{
	this->radio = radio;
}

void Esfera::dibuja()
{
	GLUquadricObj* q = gluNewQuadric();
	gluSphere(q, radio, 32, 32);
}


Esfera::~Esfera()
{
}
