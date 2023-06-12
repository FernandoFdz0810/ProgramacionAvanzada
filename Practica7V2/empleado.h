#if !defined (C_EMPLEADO_H_)
#define _CEMPLEADO_H_	

#include"cliente.h"

class CEmpleado : public CFicha
{
private:
	string m_sCategoria;	// (ej.: "Administrativo", "Tecnico"...)
	int m_nAntiguedad;		// (ej.: 3)

public:
	void SetCategoria(const string& sCategoria);
	string ObtenerCategoria() const;
	void SetAntiguedad(int nAntiguedad);
	int ObtenerAntiguedad() const;
	CEmpleado(const string& sCategoria = "", int nAntiguedad = 0, const string& nombre = "", int edad = 0, int horas = 12, int minutos = 00, int segundos = 00, const string& sFormato = "AM");	//CONSTRUCTOR POR OMISION
	CEmpleado* Clonar() { return new CEmpleado(*this); }
	void Visualizar();

};

#endif