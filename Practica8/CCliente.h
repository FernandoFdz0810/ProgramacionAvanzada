#if !defined(_CLIENTE_H)
#define _CLIENTE_H

#include <string>
#include <iostream>
#include "CLista.h"
#include "CContrato.h"

using namespace std;

class CCliente 
{
private:
  std::string m_Nombre;
  CLista<CContrato> m_Contratos;

public:
  CCliente(const std::string& Nom="Sin Nombre") : m_Nombre(Nom) {};
  CCliente(const std::string& Nom, const CContrato& c);

  void SetNombre(const std::string& Nom) {m_Nombre = Nom; }
  std::string GetNombre() const { return m_Nombre; }
  CCliente& AgregarContrato(const CContrato& c);
  CLista<CContrato> GetContratos() const { return m_Contratos; }

  operator long() const;

  friend ostream& operator<<(ostream& os, CCliente& c);
};

#endif