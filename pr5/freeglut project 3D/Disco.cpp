#include "Disco.h"


Disco::Disco(GLdouble radio)
{
	this->radio = radio;
}

void Disco::dibuja()
{
	glPushMatrix();
	glMultMatrixf(this->dameMatrizAfin());
	glColor3f(this->getRed(), this->getGreen(), this->getBlue());
	GLUquadricObj* q = gluNewQuadric();
	gluDisk(q, 0.0f, radio, 32, 32);
	glPopMatrix();
}


Disco::~Disco()
{
}
