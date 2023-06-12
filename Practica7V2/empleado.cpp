#include"empleado.h"

void CEmpleado::SetCategoria(const string& sCategoria)
{
	m_sCategoria = sCategoria;
}

void CEmpleado::SetAntiguedad(int nAntiguedad)
{
	m_nAntiguedad = nAntiguedad;
}

string CEmpleado::ObtenerCategoria() const
{
	return m_sCategoria;
}

int CEmpleado::ObtenerAntiguedad() const
{
	return m_nAntiguedad;
}

CEmpleado::CEmpleado(const string& sCategoria, int nAntiguedad, const string& nombre, int edad, int horas, int minutos, int segundos, const string& sFormato)  : m_sCategoria(sCategoria), m_nAntiguedad(nAntiguedad), CFicha(nombre, edad, horas, minutos, segundos, sFormato) {}

void CEmpleado::Visualizar()
{	
	cout << "\n **Mostrando datos del empleado**" << endl;
	CFicha::Visualizar();
	cout << "\n Categoria: " << m_sCategoria << endl;
	cout << "\n Antiguedad: " << m_nAntiguedad << endl;
}