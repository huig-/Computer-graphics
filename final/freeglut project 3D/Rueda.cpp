 
#include "Rueda.h"

Rueda:: Rueda(GLdouble anchura, GLdouble radio) : ObjetoCompuesto()
{
    this->introduceObjeto(new Cilindro(radio * 2, radio * 2, anchura));
    this->introduceObjeto(new Disco(radio * 2));
	this->introduceObjeto(new Disco(radio * 2));
	hijos[2]->traslada(0.0f, 0.0f, anchura);
	for (int i = 0; i < 2; i++) {
		hijos[i]->setRed(0.0f); 
		hijos[i]->setGreen(0.0f);
		hijos[i]->setBlue(0.0f);
	}
}
