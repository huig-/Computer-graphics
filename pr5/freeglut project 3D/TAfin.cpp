
#include "TAfin.h"
#include <math.h>

TAfin:: TAfin() {
	m = new GLfloat[16];
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
}

TAfin:: ~TAfin() {
	delete[] m;
}

GLfloat* TAfin::dameMatrizModelado() {
    return m;
}

void TAfin:: traslada(GLfloat X, GLfloat Y, GLfloat Z) {   
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
	glLoadIdentity();
	glTranslatef(X, Y, Z);
	GLfloat m1[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
    glPopMatrix();
    postMultiplica(m1);
}

void TAfin:: escala(GLfloat fX, GLfloat fY, GLfloat fZ) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
	glLoadIdentity();
	glScalef(fX, fY, fZ);
	GLfloat m1[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
    glPopMatrix();
    postMultiplica(m1);
}

void TAfin:: rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
	glLoadIdentity();
	glRotatef(alfa, fX, fY, fZ);
	GLfloat m1[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
    glPopMatrix();
    postMultiplica(m1);
}

void TAfin:: postMultiplica(GLfloat* mm) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
	glLoadMatrixf(m);
	glMultMatrixf(mm);
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
    glPopMatrix();
}
