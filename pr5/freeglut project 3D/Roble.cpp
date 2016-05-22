 
#include "Roble.h"

Roble:: Roble(int capacidad, GLdouble radioCopa, GLdouble baseTronco, GLdouble hTronco) : ObjectoCompuesto(capacidad)
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new gluSphere(q, radioCopa, 32, 32);
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
