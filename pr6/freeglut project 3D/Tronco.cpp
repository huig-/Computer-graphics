 
#include "Tronco.h"

Tronco:: Tronco(GLdouble baseTronco, GLdouble hTronco)
{
    this->introduceObjeto(new Cilindro(baseTronco, baseTronco*0.7, hTronco));
    this->introduceObjeto(new Disco(baseTronco));
    hijos[0]->rota(-90, 1, 0, 0);
    hijos[1]->rota(-90, 1, 0, 0);   
	for (int i = 0; i < 2; i++) {
		hijos[i]->setRed(0.7f); 
		hijos[i]->setGreen(0.35f);
		hijos[i]->setBlue(0.05f);
	}
}

