 
#include "Roble.h"

Roble:: Roble(GLdouble radioCopa, GLdouble baseTronco, GLdouble hTronco) 
{
    this->introduceObjeto(new Tronco(baseTronco, hTronco));
    this->introduceObjeto(new Esfera(radioCopa));
	hijos[1]->setRed(0.0f);
	hijos[1]->setGreen(0.5f);
	hijos[1]->setBlue(0.0f);
    hijos[1]->traslada(0.0f, hTronco, 0.0f);
	especular = 0;
}

void Roble::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->dameMatrizAfin());
	for (int i = 0; i < numHijos; i++) {
		glColor3f(hijos[i]->getRed(), hijos[i]->getGreen(), hijos[i]->getBlue());
		if (i == 1) {
			glEnable(GL_COLOR_MATERIAL);
			GLfloat color[] = {hijos[i]->getRed() + especular, hijos[i]->getGreen() + especular,
				hijos[i]->getBlue() + especular};
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
		}
		else {
			GLfloat color[] = { 0.0, 0.0, 0.0 };
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
		}
		hijos[i]->dibuja();
	}
	GLfloat color[] = { 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	glPopMatrix();
}

void Roble::incrementaEspecular(GLboolean inc) {
	if (inc)
		especular += 0.5;
	else especular -= 0.5;
}
