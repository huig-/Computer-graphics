#include "Coche.h"


Coche::Coche()
{
	c = new Cubo(3.0f);
}


Coche::~Coche()
{
}

void Coche::dibuja(GLUquadricObj* q, double lCubo, double rRueda)
{
	glMatrixMode(GL_MODELVIEW);
	//dibujamos el chasis
	glPushMatrix();
	glTranslated(0.0f, lCubo, 0.0f);
	dibujaChasis();
	glPopMatrix();
	
	//Dibujamos las ruedas
	glPushMatrix(); 
	glTranslated(-lCubo, 0.0f, lCubo);
	dibujaRueda(rRueda, q, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(lCubo, 0.0f, lCubo);
	dibujaRueda(rRueda, q, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(lCubo, 0.0f, -lCubo-1.5);
	dibujaRueda(rRueda, q, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-lCubo, 0.0f, -lCubo-1.5);
	dibujaRueda(rRueda, q, 1.5);
	glPopMatrix();
}

void Coche::dibujaRueda(double rRueda, GLUquadricObj* q, double anchuraRueda)
{
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluCylinder(q, rRueda*2, rRueda*2, anchuraRueda, 32, 32);
	gluDisk(q, 0.0f, rRueda * 2, 32, 32);
	glPushMatrix();
	glTranslated(0.0f, 0.0f, anchuraRueda);
	gluDisk(q, 0.0f, rRueda * 2, 32, 32);
	glPopMatrix();
}

void Coche::dibujaChasis()
{
	glColor3f(1.0f, 0.0f, 1.0f); //rosa
	c->dibuja();
}