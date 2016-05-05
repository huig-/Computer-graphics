#include "Iman.h"

const double PI = 3.141592653589793238463;


Iman::Iman(int nQ, double rInt, double rExt, double h)
{
	int m = 5; //numero de puntos en el perfil original
	PuntoVector3D** perfil = new PuntoVector3D*[m];
	//Construir el perfil
	perfil[0] = new PuntoVector3D(rInt, 0, 0, 1);
	perfil[1] = new PuntoVector3D(rExt, 0, 0, 1);
	perfil[2] = new PuntoVector3D(rExt, h, 0, 1);
	perfil[3] = new PuntoVector3D(rInt, h, 0, 1);
	perfil[4] = new PuntoVector3D(rInt, 0, 0, 1);
	int n = nQ; //numero de rotaciones

	//Tamaño de los arrays
	numeroVertices = n*m;
	numeroCaras = n*(m-1);
	numeroNormales = numeroCaras; //1 normal por cara

	//Creacion de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//Colocar el perfil original en la tabla de vertices
	for (int j = 0; j < m; j++) vertice[j] = perfil[j]->clonar();

	//Vertices de la malla
	for (int i = 1; i < n; i++) { //generar el perfil i-esimo
		double theta = i * PI / (double)(n-1);
		double c = cos(theta);
		double s = sin(theta);
		//R_y es la matriz de rotacion sobre el eje Y
		for (int j = 0; j < m; j++) {
			int indice = i*m + j;
			//Transformar el punto j-esimo del perfil original
			double x = c*perfil[j]->getX() + s*perfil[j]->getZ();
			double z = -s*perfil[j]->getX() + c*perfil[j]->getZ();
			PuntoVector3D* p = new PuntoVector3D(x, perfil[j]->getY(), z, 1);
			vertice[indice] = p;
		}
	}

	//Construcción de las caras
	int indiceCara = 0;
	for (int i = 0; i < n; i++) {  //unir el perfil i-esimo con el i+1-esimo
		for (int j = 0; j < m - 1; j++) { //esquina inferior-izquierda de una cara
			int indice = i*m + j;
			VerticeNormal** vn = new VerticeNormal*[4];
			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + m) % numeroVertices, indiceCara);
			vn[2] = new VerticeNormal((indice + 1 + m) % numeroVertices, indiceCara);
			vn[3] = new VerticeNormal(indice + 1, indiceCara);
			cara[indiceCara] = new Cara(4, vn);


			//Calcular el vector normal
			PuntoVector3D* aux2 = vertice[cara[indiceCara]->getIndiceVerticeK(2)]->clonar();
			PuntoVector3D* aux1 = vertice[cara[indiceCara]->getIndiceVerticeK(1)]->clonar();
			PuntoVector3D* aux0 = vertice[cara[indiceCara]->getIndiceVerticeK(0)]->clonar();
			aux2->restar(aux1);
			aux0->restar(aux1);
			PuntoVector3D* v = aux2->productoVectorial(aux0);
			normal[indiceCara] = v;

			indiceCara++;
		}
	}
}


Iman::~Iman()
{
	for (int i = 0; i<numeroVertices; i++)
		delete vertice[i];
	delete[] vertice;

	for (int i = 0; i<numeroNormales; i++)
		delete normal[i];
	delete[] normal;

	for (int i = 0; i<numeroCaras; i++)
		delete cara[i];
	delete[] cara;
}

void Iman::dibuja() {
	for (int i = 0; i<numeroCaras-3; i++) {
		glBegin(GL_POLYGON);
		if (i < numeroCaras/2) glColor3f(1.0f, 0.0f, 0.0f);
		else glColor3f(0.0f, 0.0f, 1.0f);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}
