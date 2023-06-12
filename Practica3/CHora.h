#include"utils.h"

class CHora {

private:
	int m_nHoras; // AM/PM: 1 a 12, 24 HORAS: 0 a 23
	int m_nMinutos; // AM/PM/24 HORAS: 0 a 59
	int m_nSegundos; // AM/PM/24 HORAS: 0 a 59
	char* m_pszFormato; //almacena los valores "AM", "PM" o "24 HORAS"

	bool AsignarFormato(char* pszFormato);
	bool Formato24() const;

protected:
	bool EsHoraCorrecta() const;

public:
	void Iniciar();
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const;
	void Destruir();
};

void VisualizarHora(const CHora& hora);
