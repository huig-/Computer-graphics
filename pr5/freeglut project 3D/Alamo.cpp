 
#include "Alamo.h"

Alamo:: Alamo(int capacidad, GLdouble radioCopa1, GLdouble radioCopa2, GLdouble baseTronco, GLdouble hTronco) : ObjectoCompuesto(capacidad)
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new CopaDobleEsferica(radioCopa1, radioCopa2));
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
}
