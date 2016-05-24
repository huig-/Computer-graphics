 
#include "Farola.h"

Farola::Farola(GLdouble rP, GLdouble hP, GLdouble rB)
{
    GLUquadricObj* q = gluNewQuadric();
    this->introduceObjeto(new gluCylinder(q, rP, rP, hP, 32, 32));
    this->introduceObjeto(new gluSphere(q, rB, 32, 32));
    hijos[1]->traslada(0.0f, hP, rP/2);
}

Farola::ilumina(GLfloat pos[3])
{
    GLfloat color[] = {1.0, 0.0, 1.0};
    GLfloat position = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat spdirection = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, color);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
    glLightfv(GL_LIGHT1, GL_SPECULAR, color);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spdirection);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, 180);
    glLightfv(GL_LIGHT1, GL_SPOT_EXPONENT, 4.0);
    glEnable(GL_LIGHT1);
}
