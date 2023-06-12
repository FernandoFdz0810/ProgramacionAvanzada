#include "CFicha.h"

using namespace utils;

//Constructor por omision
CFicha::CFicha(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato) : m_sNombre(sNombre), m_nEdad(nEdad), m_horaNacio(nHoras, nMinutos, nSegundos)
{
	AsignarNombre(sNombre);
	cout << "Constructor por omision invocado\n";
}

void CFicha::AsignarNombre(const string& sNombre)
{
	m_sNombre = sNombre;
}

void CFicha::AsignarEdad(int nEdad)
{
	m_nEdad = nEdad;
}

bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string& sFormato)
{
	// m_horaNacio es un objeto de la clase CHora, por lo que dispone de los metodos de dicha clase
	return(m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato));
}

string CFicha::ObtenerNombre() const
{
	//Devueve una copia del dato m_sNombre, Por este motivo esta apuntado por el puntero implicito this.

	return this->m_sNombre;
}

int CFicha::ObtenerEdad() const
{
	return m_nEdad;
}

CHora CFicha::ObtenerNacio() const
{
	return m_horaNacio;
}

void CFicha::Visualizar()
{
	cout << "Nombre: " << ObtenerNombre() << endl;
	cout << "Edad: " << ObtenerEdad() << endl;
	cout << "Hora Nacimiento: ";
	VisualizarHora(m_horaNacio);
}

CFicha::~CFicha(void)
{
	cout << "Destructor invocado(CFicha)." << endl;
}

void VisualizarFicha(CFicha& ficha)
{
	cout << "\n Nombre: " << ficha.ObtenerNombre() << endl;
	cout << "\n Edad: " << ficha.ObtenerEdad() << endl;
	VisualizarHora(ficha.ObtenerNacio());
}