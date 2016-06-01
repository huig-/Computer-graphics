 
#include "Foco.h"

Foco::Foco(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat dirX, GLfloat dirY, GLfloat dirZ)
{
	this->posX = posX; this->posY = posY; this->posZ = posZ;
	this->dirX = dirX; this->dirY = dirY; this->dirZ = dirZ;
	this->activo = true;
}

void Foco::setDir(GLfloat dirX, GLfloat dirY, GLfloat dirZ) 
{
	this->dirX = dirX; this->dirY = dirY; this->dirZ = dirZ;
	GLfloat d[] = { dirX, dirY, dirZ };
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, d);
}

void Foco::setPos(GLfloat posX, GLfloat posY, GLfloat posZ)
{
	this->posX = posX; this->posY = posY; this->posZ = posZ;
	GLfloat p[] = { posX, posY, posZ, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, p);
}

void Foco::activa(GLboolean enable)
{
	this->activo = enable;
	GLfloat p[] = { posX, posY, posZ, 1.0f };
	GLfloat d[] = { dirX, dirY, dirZ };
	glLightfv(GL_LIGHT1, GL_POSITION, p);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, d);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 4.0);
	//Color
	GLfloat dif0[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat esp0[] = { 1.0, 1.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif0);
	glLightfv(GL_LIGHT1, GL_SPECULAR, esp0);
	if (enable) glEnable(GL_LIGHT1);
	else glDisable(GL_LIGHT1);
}
