 
#include "Faro.h"

Faro:: Faro(GLdouble radio, GLdouble anchura) : ObjetoCompuesto()
{
    this->introduceObjeto(new Cilindro(radio * 0.9, radio, anchura));
    this->introduceObjeto(new Disco(radio));
    hijos[0]->rota(90, 0, 1, 0);
    hijos[1]->traslada(anchura, 0.0f, 0.0f);
    hijos[1]->rota(90, 0, 1, 0);
	for (int i = 0; i < 2; i++) {
		hijos[i]->setRed(0.0f);
		hijos[i]->setGreen(0.6f);
		hijos[i]->setBlue(0.0f);
	}
}
