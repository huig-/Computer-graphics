
#ifndef Coche_H_
#define Coche_H_

#include "ObjetoCompuesto.h"
#include "Rueda.h"
#include "Faro.h"
#include "Cubo.h"

class Coche: public ObjetoCompuesto {
public: Coche(GLdouble rRueda, GLdouble rFaro, GLdouble aRueda, GLdouble aFaro, GLdouble lChasis);
};
#endif
