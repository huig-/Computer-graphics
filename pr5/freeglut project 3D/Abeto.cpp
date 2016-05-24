 
#include "Abeto.h"

Abeto:: Abeto(GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco) : ObjectoCompuesto()
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new Copa(baseCopa, hCopa));
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
