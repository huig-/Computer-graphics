 
#include "Tronco.h"

Tronco:: Tronco(GLdouble baseTronco, GLdouble hTronco)
{
    this->introduceObjeto(new Cilindro(baseTronco, baseTronco*0.7, hTronco));
    this->introduceObjeto(new Disco(baseTronco));
    hijos[0]->rota(-90, 1, 0, 0);
    hijos[1]->rota(-90, 1, 0, 0);   
    this->setRed(0.7f); this->setGreen(0.35f); this->setBlue(0.05f);
}

