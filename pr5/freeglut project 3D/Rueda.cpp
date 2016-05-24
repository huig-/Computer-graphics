 
#include "Rueda.h"

Rueda:: Rueda(int capacidad, GLdouble anchura, GLdouble radio) : ObjetoCompuesto()
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new gluCylinder(q, radio * 2, radio * 2, anchura, 32, 32));
    this->introduceObjeto(new gluDisk(q, 0.0f, radio * 2, 32, 32));
    this->setRed(0.0f); this->setGreen(0.0f); this->setBlue(0.0f);
}
