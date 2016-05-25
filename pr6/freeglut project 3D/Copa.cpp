 
#include "Copa.h"

Copa:: Copa(GLdouble baseCopa, GLdouble hCopa) : ObjectoCompuesto()
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new gluCylinder(q, baseCopa, 0.0f, hCopa, 32, 32);
    this->introduceObjeto(new gluDisk(q, 0.0f, baseCopa, 32, 32);
    hijos[0]->rota(-90, 1, 0, 0);
    hijos[1]->rota(-90, 1, 0, 0);   
    this->setRed(0.0f); this->setGreen(0.5f); this->setBlue(0.0f);
}
