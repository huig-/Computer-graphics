
#include "Objeto3D.h"

Objeto3D:: Objeto3D() { 	 
    matriz = new TAfin();
}

 
Objeto3D:: ~Objeto3D() {
    delete matriz;
}

GLfloat* Objeto3D:: dameMatrizAfin() {
	return matriz->dameMatrizModelado();
}

//To do (usando las correspondientes operaciones de TAfin)
void Objeto3D:: traslada(GLfloat fX, GLfloat fY, GLfloat fZ) {
    matriz->traslada(fX, fY, fZ);
}

void Objeto3D:: escala(GLfloat fX,GLfloat fY,GLfloat fZ) {
    matriz->escala(fX, fY, fZ);
}

void Objeto3D:: rota(GLfloat alfa,GLfloat fX,GLfloat fY,GLfloat fZ) {
    matriz->rota(alfa, fX, fY, fZ);
}

GLfloat Objeto3D :: getRed() {
    return red;

}
GLfloat Objeto3D :: getGreen() {
    return green;
}

GLfloat Objeto3D :: getBlue() {
    return blue;
}

void Objeto3D::setRed(GLfloat red) {
	this->red = red;
}

void Objeto3D::setGreen(GLfloat green) {
	this->green = green;
}

void Objeto3D::setBlue(GLfloat blue) {
	this->blue = blue;
}
