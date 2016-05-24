 
#include "Tronco.h"

Tronco:: Tronco(GLdouble baseTronco, GLdouble hTronco) : ObjectoCompuesto()
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 32, 32);
    this->introduceObjeto(new gluDisk(q, 0.0f, baseTronco, 32, 32);
    hijos[0]->rota(-90, 1, 0, 0);
    hijos[1]->rota(-90, 1, 0, 0);   
    this->setRed(0.7f); this->setGreen(0.35f); this->setBlue(0.05f);
}

