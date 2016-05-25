
#ifndef Faro_H_
#define Faro_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"
#include "Foco.h"

class Faro: public ObjetoCompuesto {
public: 
	Faro(GLdouble radio, GLdouble anchura);
	void dibujaLuces();
	void dibuja();
private: 
	Foco* f;
};
#endif
