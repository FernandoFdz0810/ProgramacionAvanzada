#pragma once
#include "utils.h"

#if !defined(C_HORA_H_)
	#define _CHORA_H_

class CHora
{
private:
	int m_nHoras; // AM/PM: 1 a 12, 24 horas: 0 a 23
	int m_nMinutos;
	int m_nSegundos;
	char* m_pszFormato; // Almacena los valores "AM", "PM", o "24 HORAS"

	bool AsignarFormato(char* pszFormato);// Verifica que pszFormato no es nulo.
	// Copia en m_pszFormato el formato dado por pszFormato,
	// asignando la cantidad de memoria necesaria, y lo convierte
	// a mayúsculas. Si fuera necesario, previamente se liberará
	// la memoria que hubiera asignada. Devuelve true si la
	// operación se realiza con éxito y false en caso contrario.

	bool Formato24() const;
	// Devuelve true si el formato es "24 HORAS".
	// En otro caso, devuelve false.

public:
	void Iniciar();
	//Sera invocada cada vez que se defina un objeto
	//Pone a 0 todos los atributos de CHora.

	bool EsHoraCorrecta() const;
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos están dentro
	// de los límites según el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.

	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato);
	//Asigna los valores e invoca a AsignarFormato y a EsHoraCorrecta.
	//Devuelve false si no pudo ser asignado el formato o el valor retornado por EsHoraCorrecta.

	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const;

	void Destruir();
	// Libera la memoria reservada dinámicamente para un objeto y pone el muntero m_pszFormato a 0.


	// Creación de Contructores y Destructores
	CHora(int hh = 0, int mm = 0, int ss = 0, char* ff = (char*)"24 HORAS"); //Constructor por defecto
	CHora(const CHora& obj); // Constructor copia
	CHora& operator=(const CHora& h);
	~CHora(); 
};

void VisualizarHora(const CHora& hora);

#endif