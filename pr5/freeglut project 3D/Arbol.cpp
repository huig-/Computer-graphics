#include "Arbol.h"


Arbol::Arbol()
{
}


Arbol::~Arbol()
{
}

ObjetoCompuesto* Arbol::tronco(GLdouble baseTronco, GLdouble hTronco) 
{
    ObjetoCompuesto* obj = new ObjetoCompuesto(2);
    obj->introduceObjeto(new gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 32, 32));
    obj->introduceObjeto(new gluDisk(q, 0.0f, baseTronco, 32, 32));

}

ObjetoCompuesto* Arbol::abeto(GLUquadricObj* q, double baseTronco, double baseCopa, double hTronco, double hCopa)
{
    ObjetoCompuesto* obj = new ObjetoCompuesto(10);
    obj->introduceObjeto(new gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 32, 32);
    obj->introduceObjeto(new
    //
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glColor3f(0.7f, 0.35f, 0.05f); //marron
	gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 10000, 10000);
	gluDisk(q, 0.0f, baseTronco, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.0f, hTronco, 0.0f); //nos desplazamos a la copa
	glRotated(-90, 1, 0, 0);
	gluDisk(q, 0.0f, baseTronco*0.7, 32, 32);
	//dibujamos la copa
	glColor3f(0.0f, 0.5f, 0.0f);
	gluDisk(q, 0.0f, baseCopa, 32, 32);
	gluCylinder(q, baseCopa, 0.0f, hCopa, 32, 32);
	glPopMatrix();
	
}

void Arbol::pino(GLUquadricObj* q, double baseTronco, double baseCopa, double hTronco, double hCopa)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glColor3f(0.7f, 0.35f, 0.05f); //marron
	gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 130, 130);
	gluDisk(q, 0.0f, baseTronco, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0f, hTronco, 0.0f); //nos desplazamos a la copa
	glRotated(-90, 1, 0, 0);
	gluDisk(q, 0.0f, baseTronco*0.7, 32, 32);
	//dibujamos la copa1
	glColor3f(0.0f, 0.5f, 0.0f);
	gluDisk(q, 0.0f, baseCopa, 32, 32);
	gluCylinder(q, baseCopa, 0.0f, hCopa, 32, 32);
	glPopMatrix();
	//dibujamos la copa2
	glPushMatrix();
	glTranslated(0.0f, hTronco + hCopa/2, 0.0f);
	glRotated(-90, 1, 0, 0);
	gluDisk(q, 0.0f, baseCopa, 32, 32);
	gluCylinder(q, baseCopa, 0.0f, hCopa, 32, 32);
	glPopMatrix();
}

void Arbol::roble(GLUquadricObj* q, double baseTronco, double hTronco, double radioCopa)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glColor3f(0.7f, 0.35f, 0.05f); //marron
	gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 130, 130);
	gluDisk(q, 0.0f, baseTronco, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0f, hTronco, 0.0f); //nos desplazamos a la copa
	glRotated(-90, 1, 0, 0);
	gluDisk(q, 0.0f, baseTronco*0.7, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0f, hTronco + radioCopa-0.1, 0);
	glColor3f(0.0f, 0.5f, 0.0f);
	gluSphere(q, radioCopa, 32, 32);
	glPopMatrix();
}

void Arbol::alamo(GLUquadricObj* q, double baseTronco, double hTronco, double radioCopa1, double radioCopa2)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glColor3f(0.7f, 0.35f, 0.05f); //marron
	gluCylinder(q, baseTronco, baseTronco*0.7, hTronco, 130, 130);
	gluDisk(q, 0.0f, baseTronco, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0f, hTronco, 0.0f); //nos desplazamos a la copa
	glRotated(-90, 1, 0, 0);
	gluDisk(q, 0.0f, baseTronco*0.7, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-radioCopa1*0.4f, hTronco + radioCopa1 / 3, radioCopa1*0.4f);
	glColor3f(0.0f, 0.5f, 0.0f);
	gluSphere(q, radioCopa1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(radioCopa2*0.4f, hTronco + radioCopa2 / 3, -radioCopa2*0.4f);
	glColor3f(0.0f, 0.5f, 0.0f);
	gluSphere(q, radioCopa2, 32, 32);
	glPopMatrix();
}
