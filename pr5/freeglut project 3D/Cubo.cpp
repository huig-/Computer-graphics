#include "Cubo.h"


Cubo::Cubo(GLdouble lado)
{
	this->lado = lado;
}

void Cubo::dibuja()
{
	glPushMatrix();
	glMultMatrixf(this->dameMatrizAfin());
	glColor3f(this->getRed(), this->getGreen(), this->getBlue());
	glutSolidCube(lado*2);
	glPopMatrix();
}
