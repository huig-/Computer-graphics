
#ifndef Farola_H_
#define Farola_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Esfera.h"

class Farola: public ObjetoCompuesto {
	public: 
	    Farola(GLdouble radioP, GLdouble hP, GLdouble radioB);
	    void ilumina(GLfloat posX, GLfloat posY, GLfloat posZ);
		void dibuja();
		void setEnable(GLboolean en);
	private:
		GLboolean enable;
};
#endif
