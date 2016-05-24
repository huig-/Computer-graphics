
#ifndef Farola_H_
#define Farola_H_

#include "ObjetoCompuesto.h"

class Farola: public ObjetoCompuesto {
	public: 
	    Farola(GLdouble radioP, GLdouble hP, GLdouble radioB);
	    ilumina(GLfloat pos[3]);
};
#endif
