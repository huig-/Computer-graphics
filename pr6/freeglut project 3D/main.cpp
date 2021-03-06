#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
#include "ObjetoCompuesto.h"
#include "Coche.h"
#include "Pino.h"
#include "Abeto.h"
#include "Alamo.h"
#include "Roble.h"
#include "Farola.h"
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;
boolean ambiental = false;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Scene variables
GLfloat angX, angY, angZ; 
Coche* coche;
Pino* pino;
Abeto* abeto;
Roble* roble;
Alamo* alamo;
Farola* farola;

void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;
    coche = new Coche(0.7f, 0.5f, 1.3f, 0.4f, 2.5f);
	pino = new Pino(1.2f, 4.0f, 0.35f, 4.5f);
    abeto = new Abeto(1.2f, 4.0f, 0.35f, 3.0f);
    roble = new Roble(1.5f, 0.35f, 4.0f);
    alamo = new Alamo(2.0f, 1.8f, 0.3f, 4.0f);
	farola = new Farola(0.2f, 6.0f, 1.0f);

    pino->traslada(8.0f, 0.0f, -3.0f);
    abeto->traslada(8.0f, 0.0f, 8.0f);
    roble->traslada(-5.8f,0.0f, 6.2f);
    alamo->traslada(-2.0f, 0.0f, -5.2f);
	farola->traslada(-2.0f, 0.0f, -8.5f);
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	buildSceneObjects();

	glEnable(GL_LIGHTING); 
	GLfloat amb[] = { 0.95, 0.95, 0.95, 1.0 };
	GLfloat dif[] = {0.3, 0.9, 0.3, 1.0};
	GLfloat spe[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT3, GL_SPECULAR, spe);
	/*
    glEnable(GL_LIGHT0);
    GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);*/

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  	
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	glMatrixMode(GL_MODELVIEW);	 
	GLfloat pos[] = { 20.0, 20.0, 20.0, 1.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, pos);
	glPushMatrix();
	
		// Rotating the scene
		glRotatef(angX, 1.0f, 0.0f, 0.0f);
        glRotatef(angY, 0.0f, 1.0f, 0.0f);
        glRotatef(angZ, 0.0f, 0.0f, 1.0f);
		
		glLineWidth(1.5f);
		// Drawing axes
		glBegin( GL_LINES );			
			glColor3f(1.0,0.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(20, 0, 0);	     
	 
			glColor3f(0.0,1.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 20, 0);	 
	 
			glColor3f(0.0,0.0,1.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 20);	     
		glEnd();
		 		
		// Drawing the scene
		GLfloat amb[4];
		if (ambiental) {
			amb[0] = amb[1] = amb[2] = 0.6f;
		}
		else {
			amb[0] = amb[1] = amb[2] = 0.0f;
		}
		amb[3] = 1.0f;
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
		alamo->dibuja();
		roble->dibuja();
		pino->dibuja();
		abeto->dibuja();
		coche->dibuja();
		farola->dibuja();

	glPopMatrix();


	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		 
		case 'a': angX=angX+5; break;
		case 'z': angX=angX-5; break; 
		case 's': angY=angY+5; break;
		case 'x': angY=angY-5; break;
		case 'd': angZ=angZ+5; break;
		case 'c': angZ=angZ-5; break;  
		case 'n': coche->avanza(1.0f); break;
		case 'm': coche->avanza(-1.0f); break;
		case 'i': coche->gira(1.0f); break;
		case 'r': coche->gira(-1.0f); break;
		case 'u': ambiental = true; break;
		case 'j': ambiental = false; break;
		case 't': glEnable(GL_LIGHT1); break;
		case 'g': glDisable(GL_LIGHT1); break;
		//case '1': farola->setEnable(true); break;
		//case '2': farola->setEnable(false); break;
		case '1': glEnable(GL_LIGHT2); farola->setEnable(true); break;
		case '2':  glDisable(GL_LIGHT2); farola->setEnable(false); break;
		case 'y': glEnable(GL_LIGHT3); break;
		case 'h': glDisable(GL_LIGHT3); break;
		case 'I': roble->incrementaEspecular(true); break;
		case 'o': roble->incrementaEspecular(false); break;
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}
