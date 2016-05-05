 
#include "Camara.h"

Camara::Camara() {           
<<<<<<< HEAD
	eye=new PuntoVector3D(30, 30,30 , 1);
=======
	eye=new PuntoVector3D(30, 30, 30, 1);
>>>>>>> a18ee07f7ba1c514938b790abbb3a9e7104b69f7
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
<<<<<<< HEAD
	n = new PuntoVector3D(eye->getX(), eye->getY(), eye->getZ(), 0); n->restar(look); n->normalizar();
	u = new PuntoVector3D(up->getX(), up->getY(), up->getZ(), 0); u = u->productoVectorial(n); u->normalizar();
	v = new PuntoVector3D(n->getX(), n->getY(), n->getZ(), 0); v = v->productoVectorial(u);
	setModelViewMatrix();
=======
	n = eye->clonar(); n->restar(look); n->normalizar();
	v = up->clonar();
	u = (v->clonar())->productoVectorial(n);
	v = (n->clonar())->productoVectorial(u);
	u->normalizar();
	v->normalizar(); 
>>>>>>> a18ee07f7ba1c514938b790abbb3a9e7104b69f7
}

void Camara::setProjection() {
	//Define la matriz de proyección con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, Near, Far);
}

void Camara::setModelViewMatrix() {
    glMatrixMode(GL_MODELVIEW);		 
    GLfloat m[16];  
<<<<<<< HEAD
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ();  m[12]= -eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ();  m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0;			m[7]=0;			m[11]=0;		 m[15]=1;
=======
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ(); m[12]=-eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ(); m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0; m[7]=0; m[11]=0; m[15]=1;
>>>>>>> a18ee07f7ba1c514938b790abbb3a9e7104b69f7
    glLoadMatrixf(m); 
}

void Camara::giraX() {
<<<<<<< HEAD
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje	 
	PuntoVector3D *aux = eye->clonar(), *proyX_eye = new PuntoVector3D(eye->getX(), 0, 0, 1);
	aux->restar(proyX_eye);
	GLfloat radius = aux->modulo();
	//Calcular el angulo actual 
	//TODO
	eye = new PuntoVector3D(eye->getX(), radius * sin(0.05), radius*cos(0.05), 1);
    setView();
    setCameraCoordinateSystem(); 
=======
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje
	//TO DO	 
	PuntoVector3D* aux = (eye->clonar())->restar(look);
	GLfloat radius = aux.distancia();
	eye->sumar(new PuntoVector3D(0.0f, 0, 0, 1));
    setView();
    setCameraCoordinateSystem();     
>>>>>>> a18ee07f7ba1c514938b790abbb3a9e7104b69f7
}

void Camara::giraY() {
	//Gira la cámara alrededor del eje Y sobre un plano perpendicular a este eje
	//TO DO
}

void Camara::giraZ() {
	//Gira la cámara alrededor del eje Z sobre un plano perpendicular a este eje
	//TO DO
}

void Camara::lateral() {
	//Coloca la cámara de forma que se muestra una visión lateral 
	//de la escena (desde el eje X) 
	//TO DO
}

void Camara::frontal() {
	//Coloca la cámara de forma que se muestra una visión frontal 
	//de la escena (desde el eje Z)  
	//TO DO
}

void Camara::cenital() {
    //Coloca la cámara de forma que se muestra una visión cenital 
	//de la escena (desde el eje Y) 
	//TO DO
}

void Camara::rincon() {
    //Coloca la cámara de forma que se muestra
	//la escena en un rincón
	//TO DO
}
 
void Camara::roll(float ang) {
	//Rota la cámara tal como se explica en las transparencias
	//TO DO	 
    setModelViewMatrix();
}

void Camara::pitch(float ang) {		
    //TO DO
}

void Camara::yaw(float ang) {		
    //TO DO
}
