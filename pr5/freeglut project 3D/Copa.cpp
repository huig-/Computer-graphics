 
#include "Copa.h"

Copa:: Copa(GLdouble baseCopa, GLdouble hCopa) 
{
    this->introduceObjeto(new Cilindro(baseCopa, 0.0f, hCopa));
    this->introduceObjeto(new Disco(baseCopa));
    hijos[0]->rota(-90, 1, 0, 0);
    hijos[1]->rota(-90, 1, 0, 0);
	for (int i = 0; i < 2; i++) {
		hijos[i]->setRed(0.0f);
		hijos[i]->setGreen(0.5f);
		hijos[i]->setBlue(0.0f);
	}
}

