#include "Esfera.h"


Esfera::Esfera(GLdouble radio)
{
	this->radio = radio;
}

void Esfera::dibuja()
{
	glPushMatrix();
	glMultMatrixf(this->dameMatrizAfin());
	glColor3f(this->getRed(), this->getGreen(), this->getBlue());
	GLUquadricObj* q = gluNewQuadric();
	gluSphere(q, radio, 32, 32);
	glPopMatrix();
}


Esfera::~Esfera()
{
}
