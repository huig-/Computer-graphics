
#ifndef Roble_H_ 
#define Roble_H_

#include "ObjetoCompuesto.h"
#include "Tronco.h"
#include "Esfera.h"

class Roble: public ObjetoCompuesto {
public: Roble(GLdouble radioCopa, GLdouble baseTronco, GLdouble hTronco);
};
#endif
