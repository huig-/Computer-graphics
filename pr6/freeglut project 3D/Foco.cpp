 
#include "Foco.h"
//TODO pos tiene un ultimo dato que indica si es local o direccional: UTILIZAMOS LOCAL?
Foco::Foco(GLfloat pos[3], GLfloat dir[3])
{
    this->pos = {pos[0], pos[1], pos[2], 1.0};
    this->dir = dir;
    glLightfv(GL_LIGHT0, GL_POSITION, this->pos);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, this->dir);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 4.0);
    //Color
    GLfloat dif0[] = { 1.0, 1.0, 0.0, 1.0};
    GLfloat esp0[] = { 1.0, 1.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif0);
    glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, esp0);
}

Foco::setDir(GLfloat dir[3]) 
{
    this->dir = dir;
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, this->dir);
}

Foco::setPos(GLfloat pos[3])
{
    this->pos = {pos[0], pos[1], pos[2], 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, this->pos);
}
