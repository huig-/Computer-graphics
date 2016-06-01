
#ifndef Abeto_H_
#define Abeto_H_

#include "Copa.h"
#include "Tronco.h"
#include "ObjetoCompuesto.h"

class Abeto: public ObjetoCompuesto {
	public: 
		Abeto(GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco);
};
#endif
