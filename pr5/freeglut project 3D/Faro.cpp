 
#include "Faro.h"

Faro:: Faro(GLdouble radio, GLdouble anchura) : ObjetoCompuesto()
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new gluCylinder(q, radio * 0.9, radio, anchura, 32, 32));
    this->introduceObjeto(new gluDisk(q, 0.0f, radio, 32, 32));
    hijos[0]->rota(90, 0, 1, 0);
    hijos[1]->traslada(anchura, 0.0f, 0.0f);
    hijos[1]->rota(90, 0, 1, 0);
    this->setRed(0.0f); this->setGreen(0.6f); this->setBlue(0.0f);
}
