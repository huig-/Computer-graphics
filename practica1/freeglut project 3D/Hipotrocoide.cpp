#include "Hipotrocoide.h"
const double PI = 3.141592;


Hipotrocoide::Hipotrocoide(int nP, int nQ)
{
	a = 7; b = 4; c = 2;
	double inc = 2 * PI / nP;
	int m = nP+1; //numero de puntos en el perfil original
	PuntoVector3D** perfil = new PuntoVector3D*[m];
	//Construir el perfil
	for (int i = 0; i < nP; i++)
		perfil[i] = new PuntoVector3D(0.5*cos(i*inc), 0.5*sin(i*inc), 0, 1);
	perfil[nP] = perfil[0];

	int n = nQ; //numero de rodajas que forman el tubo
	//Tamaño de los arrays
	numeroVertices = n*m;
	numeroCaras = (n-1)*(m-1); //n*(m-1)
	numeroNormales = numeroCaras; //1 normal por cara

	//Creacion de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//Colocar el perfil original en la tabla de vertices
	for (int j = 0; j < m; j++) vertice[j] = perfil[j]->clonar();

	//Vertices de la malla
	double t = 10 * PI / nQ;
	
	for (int i = 0; i < n; i++) { //generar el perfil i-esimo
		for (int j = 0; j < m; j++) {
			construyeM(i*t);
			int indice = i*m + j;
			//Transformar el punto j-esimo del perfil original
			double x = perfil[j]->getX()*M[0] + M[1] * perfil[j]->getY()+ M[2]*perfil[j]->getZ() + M[3];
			double y = perfil[j]->getX()*M[4] + M[5] * perfil[j]->getY() + M[6] * perfil[j]->getZ() + M[7];
			double z = perfil[j]->getX()*M[8] + M[9] * perfil[j]->getY() + M[10] * perfil[j]->getZ() + M[11];
			PuntoVector3D* p = new PuntoVector3D(x, y, z, 1);
			vertice[indice] = p;
		}
	}

	//Construcción de las caras
	int indiceCara = 0;
	for (int i = 0; i < n-1; i++) {  //unir el perfil i-esimo con el i+1-esimo
		for (int j = 0; j < m-1; j++) { //esquina inferior-izquierda de una cara
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
			PuntoVector3D* v2 = new PuntoVector3D(-v->getX(), -v->getY(), -v->getZ(), 0);
			normal[indiceCara] = v2;
			//PuntoVector3D* v = aux2->productoVectorial(aux0);
			//normal[indiceCara] = v;

			indiceCara++;
		}
	}
}


Hipotrocoide::~Hipotrocoide()
{
}

PuntoVector3D* Hipotrocoide::calculaC(double t)
{
	return new PuntoVector3D((a - b)*cos(t) + c*cos(((a - b) / b)*t), 0, (a - b)*sin(t) - c*sin(((a - b) / b)*t), 1);
}

PuntoVector3D* Hipotrocoide::calculaT(double t)
{
	PuntoVector3D* dcdt = new PuntoVector3D((b - a)*sin(t) - c*((a - b) / b)*sin(((a - b) / b)*t), 0
		, (a - b)*cos(t) - c*((a - b) / b)*cos(((a - b) / b)*t), 0);
	dcdt->normalizar();
	return dcdt;
}

PuntoVector3D* Hipotrocoide::calculaB(double t)
{
	PuntoVector3D dcdt = PuntoVector3D((b - a)*sin(t) - c*((a - b) / b)*sin(((a - b) / b)*t), 0
		, (a - b)*cos(t) - c*((a - b) / b)*cos(((a - b) / b)*t), 0);
	PuntoVector3D d2cdt2 = PuntoVector3D((b - a)*cos(t) - c*((a - b) / b) *((a - b) / b) *cos(((a - b) / b)*t), 0
		, (b - a)*sin(t) + c*((a - b) / b)*((a - b) / b) *sin(((a - b) / b)*t), 0);
	PuntoVector3D* prod = dcdt.productoVectorial(&d2cdt2);
	prod->normalizar();
	return prod;
}

PuntoVector3D* Hipotrocoide::calculaN(double t)
{
	PuntoVector3D binormal = *calculaB(t);
	PuntoVector3D tangente = *calculaT(t);
	return binormal.productoVectorial(&tangente);
}

void Hipotrocoide::construyeM(double t)
{
	PuntoVector3D normal = *calculaN(t);
	PuntoVector3D binormal = *calculaB(t);
	PuntoVector3D tangente = *calculaT(t);
	PuntoVector3D curva = *calculaC(t);
	M[0] = normal.getX();
	M[1] = binormal.getX();
	M[2] = tangente.getX();
	M[3] = curva.getX();
	M[4] = normal.getY();
	M[5] = binormal.getY();
	M[6] = tangente.getY();
	M[7] = curva.getY();
	M[8] = normal.getZ();
	M[9] = binormal.getZ();
	M[10] = tangente.getZ();
	M[11] = curva.getZ();
	M[12] = 0;
	M[13] = 0;
	M[14] = 0;
	M[15] = 1;
}