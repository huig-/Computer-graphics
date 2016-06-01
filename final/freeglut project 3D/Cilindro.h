#ifndef Cilindro_H_
#define Cilindro_H_

#include "ObjetoCuadrico.h"
class Cilindro : public ObjetoCuadrico
{
public:
	Cilindro(GLdouble rBase, GLdouble rTop, GLdouble h);
	void dibuja();
	~Cilindro();
private:
	GLdouble rBase;
	GLdouble rTop;
	GLdouble h;
};
#endif
