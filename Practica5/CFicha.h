
#if !defined(C_FICHA_H_)
#define _CFICHA_H_

#include"CHora.h"

using namespace std;

class CFicha {

private:
	string m_sNombre;
	int m_nEdad;
	CHora m_horaNacio; // OJO: clase CHora de la práctica 4 versión

public:
	CFicha(const string& sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 00, int nSegundos = 00, const string& sFormato = "AM");
	void AsignarNombre(const string& sNombre);
	string ObtenerNombre() const;
	void AsignarEdad(int nEdad);
	int ObtenerEdad() const;
	bool AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string& sFormato);
	CHora ObtenerNacio() const;
	virtual void Visualizar();
	//CHora& ObternerNacio();
	//Crear destructor virtual
	virtual ~CFicha(void);
	// Funcion virtual visualizar
	//Funcion virtual Clonar. Devuelve un puntero a una copia del objeto para el cual fue invocada.
	virtual CFicha* Clonar() { return new CFicha(*this); };


	//Añadir metodos virtuales 
};

void VisualizarFicha(CFicha& ficha);
#endif