#include "CCliente.h"
#include "CContrato.h"
#include <cstdint>
using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente

CCliente::CCliente(const string& Nom, const CContrato& c) {
	this->m_Nombre = Nom;
	this->m_Contratos.AgregarObjeto(c);
}

CCliente& CCliente::AgregarContrato(const CContrato& c) {
	this->m_Contratos.AgregarObjeto(c);
	return *this;
}

ostream& operator<<(ostream& os, CCliente& c) {
	os << "nombre: " << c.m_Nombre << " contratos ";
	c.m_Contratos.Restart();
	while (c.m_Contratos.TieneMas()) {
		os << c.m_Contratos.GetActual() << " ";
	}
	c.m_Contratos.Restart();

	return os;
}

CCliente::operator long() const {
	long ret = 0;

	this->m_Contratos.Restart();
	while (this->m_Contratos.TieneMas()) {
		ret++;
		this->m_Contratos.GetActual();
	}
	this->m_Contratos.Restart();

	return ret;
}




/*
CCliente::CCliente(const string& Nom, const CContrato& c) {
	this->m_Nombre = Nom;
	this->m_Contratos.AgregarObjeto(c);
}

CCliente& CCliente::AgregarContrato(const CContrato& c)
{
	this->m_Contratos.AgregarObjeto(c);
	return *this;
}

// PREGUNTA 5: operator<< para resolver: cout << unCliente


ostream& operator<<(ostream& os, CCliente& c) {
	os << "nombre: " << c.m_Nombre << " contratos ";
	c.m_Contratos.Restart();
	while (c.m_Contratos.TieneMas()) {
		os << c.m_Contratos.GetActual() << " ";
	}
	c.m_Contratos.Restart();

	return os;
}

// PREGUNTA 9: total += seguros[i]

CCliente::operator long() const
{
	long ret = 0;

	this->m_Contratos.Restart();
	while (this->m_Contratos.TieneMas()) {
		ret++;
		this->m_Contratos.GetActual();
	}
	this->m_Contratos.Restart();

	return ret;
}
*/
