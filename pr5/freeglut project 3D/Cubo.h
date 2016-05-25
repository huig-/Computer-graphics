#ifndef Cubo_H_
#define Cubo_H_

#include "ObjetoCompuesto.h"
class Cubo : public ObjetoCompuesto
{
public:
	Cubo(GLdouble lado);
	void dibuja();
private:
	GLdouble lado;
};
#endif
