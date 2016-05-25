 
#include "Rueda.h"

Rueda:: Rueda(GLdouble anchura, GLdouble radio) : ObjetoCompuesto()
{
    this->introduceObjeto(new Cilindro(radio * 2, radio * 2, anchura));
    this->introduceObjeto(new Disco(radio * 2));
    this->setRed(0.0f); this->setGreen(0.0f); this->setBlue(0.0f);
}
