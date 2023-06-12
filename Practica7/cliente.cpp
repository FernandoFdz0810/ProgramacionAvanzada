//#include "CFicha.h"
#include "cliente.h"

using namespace std;

CCliente::CCliente(const string& sDNI, const string& nombre, int edad, int horas, int minutos, int segundos, const string& sFormato) : m_sDNI(sDNI), CFicha(nombre, edad, horas, minutos, segundos, sFormato)  {}

void CCliente::SetDNI(const string& sDNI)
{
		m_sDNI = sDNI;
	
}
void CCliente::Visualizar()
{
	cout << "\n Mostrando datos del Cliente:\n";
	CFicha::Visualizar();
	cout << "\n DNI: " << m_sDNI << endl;
}

