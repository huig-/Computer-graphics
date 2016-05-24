
#ifndef Coche_H_
#define Coche_H_

#include "Objeto3D.h"
#include "Rueda.h"
#include "Faro.h"

class Coche: public ObjetoCompuesto {
    public Coche(GLdouble rRueda, GLdouble rFaro, GLdouble aRueda, GLdouble aFaro, GLdouble lChasis);
};
#endif
