 
#include "Pino.h"

Pino:: Pino(GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco) 
{
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new CopaDoble(baseCopa, hCopa));
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
