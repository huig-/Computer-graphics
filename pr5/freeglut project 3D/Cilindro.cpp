#include "Cilindro.h"


Cilindro::Cilindro(GLdouble rBase, GLdouble rTop, GLdouble h)
{
	this->rBase = rBase;
	this->rTop = rTop;
	this->h = h;
}


Cilindro::~Cilindro()
{
}

void Cilindro::dibuja()
{
	glPushMatrix();
	glMultMatrixf(this->dameMatrizAfin());
	glColor3f(this->getRed(), this->getGreen(), this->getBlue());
	GLUquadricObj* q = gluNewQuadric();
	gluCylinder(q, rBase, rTop, h, 32, 32);
	glPopMatrix();
}
