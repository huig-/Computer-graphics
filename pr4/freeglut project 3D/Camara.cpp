 
#include "Camara.h"

Camara::Camara() {           
	eye=new PuntoVector3D(30, 30, 30, 1);
    look=new PuntoVector3D(0, 0, 0, 1);
    up=new PuntoVector3D(0, 1, 0, 0);
	angleX = 0; angleY = 0; angleZ = 0;
       
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
	n = new PuntoVector3D(eye->getX(), eye->getY(), eye->getZ(), 0); n->restar(look); n->normalizar();
	u = new PuntoVector3D(up->getX(), up->getY(), up->getZ(), 0); u = u->productoVectorial(n); u->normalizar();
	v = new PuntoVector3D(n->getX(), n->getY(), n->getZ(), 0); v = v->productoVectorial(u);
	setModelViewMatrix();
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
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ();  m[12]= -eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ();  m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0;			m[7]=0;			m[11]=0;		 m[15]=1;
    glLoadMatrixf(m); 
}

void Camara::giraX() {
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje	 
	PuntoVector3D *aux = eye->clonar(), *proyX_eye = new PuntoVector3D(eye->getX(), 0, 0, 1);
	aux->restar(proyX_eye);
	GLfloat radius = aux->modulo();
	//Calcular el angulo actual 
	PuntoVector3D eje(eye->getX(), 0, 1, 0);
	//GLfloat angle = atan2(aux->productoVectorial((aux->productoVectorial(eje)), aux->productoEscalar(eje));
	eye = new PuntoVector3D(eye->getX(), radius * sin(0.05+angleX), radius*cos(angleX+0.05), 1);
	angleX += 0.05;
	setView();
	setCameraCoordinateSystem(); 
}

void Camara::giraY() {
	//Gira la cámara alrededor del eje Y sobre un plano perpendicular a este eje
	PuntoVector3D *aux = eye->clonar(), *proyY_eye = new PuntoVector3D(0, eye->getY(), 0, 1);
	aux->restar(proyY_eye);
	GLfloat radius = aux->modulo();
	//Calcular el angulo actual
	PuntoVector3D eje(0, eye->getY(), 1, 0);
//	GLfloat angle = atan2(aux->productoVectorial((aux->productoVectorial(eje))->normalizar(), aux->productoEscalar(eje));
	eye = new PuntoVector3D(radius * sin(angleY+0.05), eye->getY(), radius*cos(angleY+0.05), 1);
	angleY += 0.05;
	setView();
	setCameraCoordinateSystem(); 

}

void Camara::giraZ() {
	//Gira la cámara alrededor del eje Z sobre un plano perpendicular a este eje
	PuntoVector3D *aux = eye->clonar(), *proyZ_eye = new PuntoVector3D(0, 0, eye->getZ(), 1);
	aux->restar(proyZ_eye);
	GLfloat radius = aux->modulo();
	//Calcular el angulo actual
	PuntoVector3D eje(0, 0, eye->getZ(), 0);
//	GLfloat angle = atan2(aux->productoVectorial((aux->productoVectorial(eje))->normalizar(), aux->productoEscalar(eje));
	eye = new PuntoVector3D(radius * sin(angleZ+0.05), radius*cos(angleZ+0.05), eye->getZ(), 1);
	angleZ += 0.05;
	setView();
	setCameraCoordinateSystem(); 

}

void Camara::lateral() {
	//Coloca la cámara de forma que se muestra una visión lateral 
	//de la escena (desde el eje X) 
	eye = new PuntoVector3D(30, 0, 0, 1);
	up = new PuntoVector3D(0, 1, 0, 0);
	setView();
	setCameraCoordinateSystem();
}

void Camara::frontal() {
	//Coloca la cámara de forma que se muestra una visión frontal 
	//de la escena (desde el eje Z)  
	eye = new PuntoVector3D(0, 0, 30, 1);
	up = new PuntoVector3D(0, 1, 0, 0);
	setView();
	setCameraCoordinateSystem();
}

void Camara::cenital() {
    //Coloca la cámara de forma que se muestra una visión cenital 
    //de la escena (desde el eje Y) 
    eye = new PuntoVector3D(0, 30, 0, 1);
    up = new PuntoVector3D(1, 0, 0, 0);
    setView();
    setCameraCoordinateSystem();
}

void Camara::rincon() {
    //Coloca la cámara de forma que se muestra
    //la escena en un rincón
    eye = new PuntoVector3D(30, 30, 30, 1);
    up = new PuntoVector3D(0, 1, 0, 0);
    setView();
    setCameraCoordinateSystem();
}
 
void Camara::roll(float ang) {
    //Rota la cámara tal como se explica en las transparencias
	//PuntoVector3D *u_aux = (u->clonar()); u_aux->escalar(cos(ang))->sumar(v->clonar()->escalar(sin(ang)));
    //PuntoVector3D *v_aux = (u->clonar())->escalar(-sin(ang))->sumar(v->clonar()->escalar(cos(ang)));
    //u = u_aux; 
    //v = v_aux;
    setModelViewMatrix();
}

void Camara::pitch(float ang) {		
    //PuntoVector3D *v' = v->clonar()->escalar(cos(ang))->sumar(n->clonar()->escalar(sin(ang)));
    //PuntoVector3D *n' = v->clonar()->escalar(-sin(ang))->sumar(n->clonar()->escalar(cos(ang)));
    //v = v';
    //n = n';
    setModelViewMatrix();
}

void Camara::yaw(float ang) {		
    //PuntoVector3D *u' = u->clonar()->escalar(cos(ang))->restar(n->clonar()->escalar(sin(ang)));
    //PuntoVector3D *n' = u->clonar()->escalar(sin(ang))->sumar(n->clonar()->escalar(cos(ang)));
    //u = u';
    //n = n';
    setModelViewMatrix();
}

void Camara::zoom(GLdouble factor) {
    GLdouble width = right - left;
    GLdouble height = top - bottom;
    GLdouble depth = Far - Near;

    GLdouble newWidth = width/factor, newHeight = height/factor, newDepth = depth/factor;
    left = look->getX() - newWidth/2.0;
    right = look->getX() + newWidth/2.0;
    bottom = look->getY() - newHeight/2.0;
    top = look->getY() + newHeight/2.0;
    Near = look->getZ() - newDepth/2.0;
    Far = look->getZ() + newDepth/2.0;
    setProjection();
}

GLfloat Camara::getLeft() {
    return left;
}

GLfloat Camara::getRight() {
    return right;
}

GLfloat Camara::getBottom() {
    return bottom;
}

GLfloat Camara::getTop() {
    return top;
}

GLfloat Camara::getNear() {
    return Near;
}

GLfloat Camara::getFar() {
    return Far;
}
