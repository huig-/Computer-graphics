 
#include "Abeto.h"

Abeto:: Abeto(int capacidad, GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco) : ObjectoCompuesto(capacidad)
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new Copa(baseCopa, hCopa));
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
