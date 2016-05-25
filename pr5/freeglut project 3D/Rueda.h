
#ifndef Rueda_H_
#define Rueda_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"

class Rueda: public ObjetoCompuesto {
public: Rueda(GLdouble anchura, GLdouble radio);
};
#endif
