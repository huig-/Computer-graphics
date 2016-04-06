#pragma once
#include "Malla.h"
class Iman :
	public Malla
{
public:
	Iman(int nQ, double rInt, double rExt, double h);
	~Iman();
	void dibuja();
};

