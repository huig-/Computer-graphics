#pragma once
#include "ObjetoCuadrico.h"
class Disco :
	public ObjetoCuadrico
{
public:
	Disco(GLdouble radio);
	void dibuja();
	~Disco();
private:
	GLdouble radio;
};

