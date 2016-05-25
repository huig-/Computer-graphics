 
#include "Copa.h"

Copa:: Copa(GLdouble baseCopa, GLdouble hCopa) 
{
    this->introduceObjeto(new Cilindro(baseCopa, 0.0f, hCopa));
    this->introduceObjeto(new Disco(baseCopa));
    hijos[0]->rota(-90, 1, 0, 0);
    hijos[1]->rota(-90, 1, 0, 0);   
    this->setRed(0.0f); this->setGreen(0.5f); this->setBlue(0.0f);
}

