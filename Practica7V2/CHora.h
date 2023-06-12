#include"utils.h"

#if !defined(C_HORA_H_)
#define _CHORA_H_

class CHora {

private:
	int m_nHoras; // AM/PM: 1 a 12, 24 HORAS: 0 a 23
	int m_nMinutos; // AM/PM/24 HORAS: 0 a 59
	int m_nSegundos; // AM/PM/24 HORAS: 0 a 59
	std::string m_pszFormato; //almacena los valores "AM", "PM" o "24 HORAS"

	bool AsignarFormato(string pszFormato);
	bool Formato24() const;

public:
	void Iniciar();
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, string pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const;
	void Destruir();
	bool EsHoraCorrecta() const;

	//Constructores y destructores
	CHora(int hh = 0, int mm = 0, int ss = 0, string ff = "24 HORAS");	// CONSTRUCTOR POR OMISION
	CHora(const CHora& obj);					// CONSTRUCTOR COPIA
	CHora& operator= (const CHora& obj_asg);	// OPERADOR ASIGNACION
	~CHora();									// DESTRUCTOR
};

void VisualizarHora(const CHora& hora);

#endif