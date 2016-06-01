
#ifndef Foco_H_
#define Foco_H_

#include <GL/freeglut.h>

class Foco{
    public:
		Foco(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat dirX, GLfloat dirY, GLfloat dirZ);
		void setPos(GLfloat posX, GLfloat posY, GLfloat posZ);
		void setDir(GLfloat dirX, GLfloat dirY, GLfloat dirZ);
		void activa(GLboolean enable);
    private:
		GLfloat posX, posY, posZ;
		GLfloat dirX, dirY, dirZ;
		GLboolean activo;
};
#endif
