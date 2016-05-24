 
#include "CopaDobleEsferica.h"

CopaDobleEsferica:: CopaDobleEsferica(GLdouble radioCopa1, GLdouble radioCopa2) : ObjectoCompuesto()
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new gluSphere(q, radioCopa1, 32, 32));
    this->introduceObjeto(new gluSphere(q, radioCopa2, 32, 32));
    hijos[1]->traslada(radioCopa2 * 0.4f, 0, 0);
    this->setRed(0.0f); this->setGreen(0.5f); this->setBlue(0.0f);
}

