 
#include "CopaDobleEsferica.h"

CopaDobleEsferica:: CopaDobleEsferica(GLdouble radioCopa1, GLdouble radioCopa2) 
{
    this->introduceObjeto(new Esfera(radioCopa1));
    this->introduceObjeto(new Esfera(radioCopa2));
    hijos[1]->traslada(radioCopa2 * 0.4f, 0, 0);
    this->setRed(0.0f); this->setGreen(0.5f); this->setBlue(0.0f);
}

