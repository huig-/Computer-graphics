
#ifndef Cubo_H_
#define Cubo_H_

#include "Malla.h"
 
class Cubo : public Malla {	 
    public:
        Cubo(double l);
        ~Cubo(); 
		void dibuja();
};
#endif