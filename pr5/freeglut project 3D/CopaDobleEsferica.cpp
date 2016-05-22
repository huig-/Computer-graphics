 
#include "CopaDobleEsferica.h"

CopaDobleEsferica:: CopaDobleEsferica(int capacidad, GLdouble radioCopa1, GLdouble radioCopa2) : ObjectoCompuesto(capacidad)
{
    GLUquadricObj* q = new gluNewQuadric();
    this->introduceObjeto(new gluSphere(q, radioCopa1, 32, 32));
    this->introduceObjeto(new gluSphere(q, radioCopa2, 32, 32));
    hijos[1]->traslada(radioCopa2 * 0.4f, 0, 0);
}

