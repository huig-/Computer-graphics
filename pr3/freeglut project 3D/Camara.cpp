 
#include "Camara.h"

Camara::Camara() {           
	eye=new PuntoVector3D(30, 30, 30, 1);
    look=new PuntoVector3D(0, 0, 0, 1);
    up=new PuntoVector3D(0, 1, 0, 0);
       
    left=-10; right=-left; bottom=-10; top=-bottom; 
	Near=1; Far=1000;
	fovy=5; aspect=2.5; 
	  
	setView();  
	setProjection();
	setCameraCoordinateSystem();		
	
}

void Camara::setView() {
	//Define la matriz de vista con el comando gluLookAt() 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->getX(), eye->getY(), eye->getZ(),
		look->getX(), look->getY(), look->getZ(),
		up->getX(), up->getY(), up->getZ());
}

void Camara::setCameraCoordinateSystem() {
	//Obtiene el valor de los vectores u, v, n 
	n = eye->clonar(); n->restar(look); n->normalizar();
	v = up->clonar();
	u = (v->clonar())->productoVectorial(n);
	v = (n->clonar())->productoVectorial(u);
	u->normalizar();
	v->normalizar(); 
}

void Camara::setProjection() {
	//Define la matriz de proyecci�n con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, Near, Far);
}

void Camara::setModelViewMatrix() {
    glMatrixMode(GL_MODELVIEW);		 
    GLfloat m[16];  
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ(); m[12]=-eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ(); m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0; m[7]=0; m[11]=0; m[15]=1;
    glLoadMatrixf(m); 
}

void Camara::giraX() {
	//Gira la c�mara alrededor del eje X sobre un plano perpendicular a este eje
	//TO DO	 
	PuntoVector3D* aux = (eye->clonar())->restar(look);
	GLfloat radius = aux.distancia();
	eye->sumar(new PuntoVector3D(0.0f, 0, 0, 1));
    setView();
    setCameraCoordinateSystem();     
}

void Camara::giraY() {
	//Gira la c�mara alrededor del eje Y sobre un plano perpendicular a este eje
	//TO DO
}

void Camara::giraZ() {
	//Gira la c�mara alrededor del eje Z sobre un plano perpendicular a este eje
	//TO DO
}

void Camara::lateral() {
	//Coloca la c�mara de forma que se muestra una visi�n lateral 
	//de la escena (desde el eje X) 
	//TO DO
}

void Camara::frontal() {
	//Coloca la c�mara de forma que se muestra una visi�n frontal 
	//de la escena (desde el eje Z)  
	//TO DO
}

void Camara::cenital() {
    //Coloca la c�mara de forma que se muestra una visi�n cenital 
	//de la escena (desde el eje Y) 
	//TO DO
}

void Camara::rincon() {
    //Coloca la c�mara de forma que se muestra
	//la escena en un rinc�n
	//TO DO
}
 
void Camara::roll(float ang) {
	//Rota la c�mara tal como se explica en las transparencias
	//TO DO	 
    setModelViewMatrix();
}

void Camara::pitch(float ang) {		
    //TO DO
}

void Camara::yaw(float ang) {		
    //TO DO
}
