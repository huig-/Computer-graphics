 
#include "Pino.h"

Pino:: Pino(GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco) 
{
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new Copa(baseCopa, hCopa));
    this->introduceObjeto(new Copa(baseCopa, hCopa));
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
    hijos[2]->traslada(0.0f, hTronco + hCopa/2, 0.0f);
}
