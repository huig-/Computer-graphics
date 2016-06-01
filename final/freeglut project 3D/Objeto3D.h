
#ifndef Objeto3D_H_
#define Objeto3D_H_

#include "PuntoVector3D.h"
#include "TAfin.h"
  
class Objeto3D {
   protected:   
		TAfin* matriz;
		GLfloat red;
		GLfloat green;
		GLfloat blue;
		
   public:	  	   
	    Objeto3D();    
		~Objeto3D();
		virtual void dibuja()=0;
		void traslada(GLfloat fX, GLfloat fY, GLfloat fZ);
		void escala(GLfloat fX,GLfloat fY,GLfloat fZ);
		void rota(GLfloat alfa,GLfloat fX,GLfloat fY,GLfloat fZ);
		GLfloat* dameMatrizAfin();
		GLfloat getRed();
		GLfloat getGreen();
		GLfloat getBlue();
		void setRed(GLfloat red);
		void setGreen(GLfloat green);
		void setBlue(GLfloat blue);
};

#endif
