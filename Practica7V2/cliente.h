#if !defined(_CLIENTE_H_)
#define _CLIENTE_H_

//#include <iostream>
#include "CFicha.h"

using namespace std;

class CCliente : public CFicha
{

private:
	string m_sDNI;

public:
	CCliente(const string& m_sDNI = "", const string& nombre = "", int edad = 0, int horas = 12, int minutos = 00, int segundos = 00, const string& sFormato = "AM");
	void SetDNI(const string& sDNI);
	void Visualizar();
	CCliente* Clonar() { return new CCliente(*this); }

};


#endif