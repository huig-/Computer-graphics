 
#ifndef CamaraH
#define CamaraH

#include "PuntoVector3D.h"
 
class Camara {
	private:
		PuntoVector3D *eye, *up, *look, *u, *v, *n;				
        GLfloat left, right, bottom, top, Near, Far;                
        GLdouble fovy, aspect; 		 
		GLfloat angleX, angleY, angleZ;
		GLboolean ortho;
		void setView();	
		void setCameraCoordinateSystem();
        void setModelViewMatrix();

	public:				
		Camara();		 
                                                                     
        void giraX();
        void giraY();
        void giraZ();
        void lateral();
        void frontal();
        void cenital();
        void rincon(); 
	void setProjection(); 
	void roll(float ang);
        void pitch(float ang);
        void yaw(float ang);      
		void zoom(GLdouble factor);
	void setAngle(GLfloat angle);
	void setOrtho(GLboolean b);
	GLfloat getAngle();
	GLfloat getLeft();
	GLfloat getRight();
	GLfloat getBottom();
	GLfloat getTop();
	GLfloat getNear();
	GLfloat getFar();
};
#endif
