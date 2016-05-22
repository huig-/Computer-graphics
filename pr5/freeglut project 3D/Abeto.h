
#ifndef Abeto_H_
#define Abeto_H_

#include "Objeto3D.h"
#include "Copa.h"
#include "Tronco.h"

class Abeto: public ObjetoCompuesto {
    public Abeto(int capacidad, GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco);
};
#endif
