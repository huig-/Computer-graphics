#include "Coche.h"


Coche::Coche()
{
	lCubo = 2.5f;
	rRueda = 0.7f;
	anchuraRueda = 1.0f;
	rFaro = 0.5f;
	anchuraFaro = 0.4f;
	c = new Cubo(lCubo);
}


Coche::~Coche()
{
}

void Coche::dibuja(GLUquadricObj* q)
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
	dibujaRueda(q);
	glPopMatrix();

	glPushMatrix();
	glTranslated(lCubo, 0.0f, lCubo);
	dibujaRueda(q);
	glPopMatrix();

	glPushMatrix();
	glTranslated(lCubo, 0.0f, -lCubo-anchuraRueda);
	dibujaRueda(q);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-lCubo, 0.0f, -lCubo-anchuraRueda);
	dibujaRueda(q);
	glPopMatrix();

	//Dibujamos las luces
	glPushMatrix();
	glTranslated(lCubo, 0.3*lCubo, -0.4*lCubo);
	dibujaLuces(q);
	glPopMatrix();

	glPushMatrix();
	glTranslated(lCubo, 0.3*lCubo, 0.4*lCubo);
	dibujaLuces(q);
	glPopMatrix();
}

void Coche::dibujaRueda(GLUquadricObj* q)
{
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 0.0f, 0.0f); //negro
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

void Coche::dibujaLuces(GLUquadricObj* q)
{
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 0.6f, 0.0f); 
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	gluCylinder(q, 0.9*rFaro, rFaro, anchuraFaro, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslated(anchuraFaro, 0.0f, 0.0f);
	glRotated(90, 0, 1, 0);
	gluDisk(q, 0.0f, rFaro, 32, 32);
	glPopMatrix();
}