
#ifndef Roble_H_ 
#define Roble_H_

#include "Objeto3D.h"
#include "Tronco.h"

class Roble: public ObjetoCompuesto {
    public Roble(int capacidad, GLdouble radioCopa, GLdouble baseTronco, GLdouble hTronco);
};
#endif
