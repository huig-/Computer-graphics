 
#include "Roble.h"

Roble:: Roble(GLdouble radioCopa, GLdouble baseTronco, GLdouble hTronco) 
{
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new Esfera(radioCopa));
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
