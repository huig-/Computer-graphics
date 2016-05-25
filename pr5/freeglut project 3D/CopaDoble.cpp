#include "CopaDoble.h"


CopaDoble::CopaDoble(GLdouble baseCopa, GLdouble hCopa)
{
	this->introduceObjeto(new Copa(baseCopa, hCopa));
	this->introduceObjeto(new Copa(baseCopa, hCopa));
	hijos[1]->traslada(0.0f, hCopa/2, 0.0f);
}


CopaDoble::~CopaDoble()
{
}
