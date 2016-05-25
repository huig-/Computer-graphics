 
#include "Coche.h"

Coche:: Coche(GLdouble rRueda, GLdouble rFaro, GLdouble aRueda, GLdouble aFaro, GLdouble lChasis)
{
    this->introduceObjeto(new Cubo(lChasis));
    for (int i = 0; i < 4; i++)
        this->introduceObjeto(new Rueda(aRueda, rRueda));
    for (int i = 0; i < 2; i++)
	this->introduceObjeto(new Faro(rFaro, aFaro)); 
    
    hijos[0]->traslada(0.0f, lChasis, 0.0f); //chasis 
	hijos[0]->setRed(1.0f);
	hijos[0]->setGreen(0.6f);
	hijos[0]->setBlue(0.0f);
    hijos[1]->traslada(-lChasis, 0.0f, lChasis); //rueda1
    hijos[2]->traslada(lChasis, 0.0f, lChasis); //rueda2
    hijos[3]->traslada(lChasis, 0.0f, -lChasis -aRueda); //rueda3
    hijos[4]->traslada(-lChasis, 0.0f, -lChasis -aRueda); //rueda4
    hijos[5]->traslada(lChasis, 0.3 * lChasis, -0.4 * lChasis); //faro1
    hijos[6]->traslada(lChasis, 0.3 * lChasis, 0.4 * lChasis); //faro2 
}
