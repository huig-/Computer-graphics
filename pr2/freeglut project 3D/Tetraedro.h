#include "Malla.h"
class Tetraedro :
	public Malla
{
protected:
	int modo;
public:
	Tetraedro();
	~Tetraedro();
	void dibuja();
	void cambia_modo();
};

