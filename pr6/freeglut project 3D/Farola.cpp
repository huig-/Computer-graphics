 
#include "Farola.h"

Farola::Farola(GLdouble rP, GLdouble hP, GLdouble rB)
{
    GLUquadricObj* q = gluNewQuadric();
    this->introduceObjeto(new Cilindro(rP, rP, hP));
    this->introduceObjeto(new Esfera(rB));
	hijos[0]->rota(-90, 1.0f, 0.0f, 0.0f);
    hijos[1]->traslada(0.0f, hP, 0.0f);
	hijos[1]->setRed(1.0f);
	hijos[1]->setGreen(1.0f);
	hijos[1]->setBlue(1.0f);
	this->enable = false;
}

void Farola::ilumina(GLfloat posX, GLfloat posY, GLfloat posZ)
{
    GLfloat amb[] = {0.6, 0.0, 0.6};
	GLfloat dif[] = { 0.8, 0.0, 0.8 };
	GLfloat spe[] = { 1.0, 1.0, 1.0 };
	GLfloat amb_no[] = { 0.0f, 0.0f, 0.0f };
    GLfloat position[] = {posX, posY, posZ, 1.0f};
    GLfloat spdirection[] = {0.0f, 0.0f, 0.0f, 1.0f};
	if (enable)
	 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, amb);
	else
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, amb_no);
    glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT2, GL_SPECULAR, spe);
    glLightfv(GL_LIGHT2, GL_POSITION, position);
   // glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spdirection);
    //glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, 180);
    //glLightfv(GL_LIGHT1, GL_SPOT_EXPONENT, 4.0);
}

void Farola::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->dameMatrizAfin());
	ilumina(0.0f, 6.0f, 0.0f);
	for (int i = 0; i < numHijos; i++) {
		glColor3f(hijos[i]->getRed(), hijos[i]->getGreen(), hijos[i]->getBlue());
		hijos[i]->dibuja();
	}
	glPopMatrix();
	GLfloat amb[] = { 0.0f, 0.0f, 0.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, amb);
}

void Farola::setEnable(GLboolean en)
{
	this->enable = en;
}
