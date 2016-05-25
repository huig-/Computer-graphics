#pragma once
#include "ObjetoCompuesto.h"
#include "Copa.h"
class CopaDoble :
	public ObjetoCompuesto
{
public:
	CopaDoble(GLdouble baseCopa, GLdouble hCopa);
	~CopaDoble();
};

