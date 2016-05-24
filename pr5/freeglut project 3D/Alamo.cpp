 
#include "Alamo.h"

Alamo:: Alamo(GLdouble radioCopa1, GLdouble radioCopa2, GLdouble baseTronco, GLdouble hTronco) 
{
    GLUquadricObj* q = gluNewQuadric();
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new CopaDobleEsferica(radioCopa1, radioCopa2));
    hijos[1]->traslada(0.0f, hTronco, baseTronco/2);
}
