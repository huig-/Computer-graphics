#include "Disco.h"


Disco::Disco(GLdouble radio)
{
	this->radio = radio;
}

void Disco::dibuja()
{
	GLUquadricObj* q = gluNewQuadric();
	gluDisk(q, 0.0f, radio, 32, 32);
}


Disco::~Disco()
{
}
