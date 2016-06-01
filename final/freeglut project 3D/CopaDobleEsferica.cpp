 
#include "CopaDobleEsferica.h"

CopaDobleEsferica:: CopaDobleEsferica(GLdouble radioCopa1, GLdouble radioCopa2) 
{
    this->introduceObjeto(new Esfera(radioCopa1));
    this->introduceObjeto(new Esfera(radioCopa2));
    hijos[1]->traslada(radioCopa2 * 0.7f, 0, -radioCopa2 * 0.7f);
	for (int i = 0; i < 2; i++) {
		hijos[i]->setRed(0.0f);
		hijos[i]->setGreen(0.5f);
		hijos[i]->setBlue(0.0f);
	}
}

