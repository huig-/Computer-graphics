
#ifndef ObjetoCompuesto_H_
#define ObjetoCompuesto_H_

#include "Objeto3D.h"

class ObjetoCompuesto: public Objeto3D {
	protected:
		Objeto3D** hijos;
		int numHijos;
		int capacidad;
	public:
		ObjetoCompuesto(int capacidad = 100);
		~ObjetoCompuesto();
		void dibuja();
		void introduceObjeto(Objeto3D* objeto);
};
#endif
