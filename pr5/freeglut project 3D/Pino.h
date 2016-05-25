
#ifndef Pino_H_
#define Pino_H_

#include "Objeto3D.h"
#include "Copa.h"
#include "Tronco.h"

class Pino: public ObjetoCompuesto {
public: Pino(GLdouble baseCopa, GLdouble hCopa, GLdouble baseTronco, GLdouble hTronco);
};
#endif
