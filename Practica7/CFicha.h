#include"CHora.h"

#if !defined(C_FICHA_H_)
#define _CFICHA_H_

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
	//CHora& ObternerNacio();
	virtual ~CFicha(void); //Es virtual
	//void VisualizarFicha();
	virtual void Visualizar();
	virtual CFicha* Clonar() { return new CFicha(*this); }//copia objetos derivados de CFicha //revisar en constructor copia cuando se haga
};



#endif