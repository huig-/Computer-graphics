#ifndef Esfera_H_
#define Esfera_H_

#include "ObjetoCuadrico.h"
class Esfera : public ObjetoCuadrico
{
public:
	Esfera(GLdouble radio);
	void dibuja();
	~Esfera();
private:
	GLdouble radio;
};
#endif

