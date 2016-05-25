 
#include "Roble.h"

Roble:: Roble(GLdouble radioCopa, GLdouble baseTronco, GLdouble hTronco) 
{
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new Esfera(radioCopa));
	hijos[1]->setRed(0.0f);
	hijos[1]->setGreen(0.5f);
	hijos[1]->setBlue(0.0f);
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
