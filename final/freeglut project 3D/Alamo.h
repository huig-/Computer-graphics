
#ifndef Alamo_H_
#define Alamo_H_

#include "ObjetoCompuesto.h"
#include "CopaDobleEsferica.h"
#include "Tronco.h"

class Alamo: public ObjetoCompuesto {
	public: 
		Alamo(GLdouble radioCopa1, GLdouble radioCopa2, GLdouble baseTronco, GLdouble hTronco);
};
#endif
