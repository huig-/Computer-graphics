 
#include "ObjetoCompuesto.h"

ObjetoCompuesto:: ObjetoCompuesto(int capacidad) {
	hijos = new Objeto3D*[capacidad];
	numHijos = 0;
	this->capacidad = capacidad;
}

ObjetoCompuesto:: ~ObjetoCompuesto() {
	for(int i =0; i < numHijos; i++) {     
		delete hijos[i];
    }  
}

void ObjetoCompuesto:: dibuja() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix(); 
	glMultMatrixf(this->dameMatrizAfin());
	for (int i = 0; i < numHijos; i++) {
	    glColor3f(hijos[i]->getRed(), hijos[i]->getGreen(), hijos[i]->getBlue());
	    hijos[i]->dibuja();
	}
    glPopMatrix();
}

void ObjetoCompuesto:: introduceObjeto(Objeto3D* objeto) {
    if (numHijos < capacidad) {
	hijos[numHijos] = objeto;
	numHijos++;
    }
}




