#include "CLista.h"
#include "CSiniestro.h"
#include "CContrato.h"
#include <iostream>
#include <string>
#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
  : m_NumSerie(NumSerie), m_Descripcion(Desc),
  m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

//Operador de asignación 

CContrato& CContrato::operator=(const CContrato& c)
{
    if (this == &c) // Comprobar autoasignación
        return *this;

    // Copiar los miembros individuales
    m_NumSerie = c.m_NumSerie;
    m_Descripcion = c.m_Descripcion;
    m_FechaFin = c.m_FechaFin;
    m_Poliza = c.m_Poliza;
    m_ValorCompra = c.m_ValorCompra;

    // Copiar la lista de siniestros
    m_Siniestros = c.m_Siniestros;

    return *this;
}

//Constructor copia

CContrato::CContrato(const CContrato& c)
    : m_NumSerie(c.m_NumSerie),
    m_Descripcion(c.m_Descripcion),
    m_FechaFin(c.m_FechaFin),
    m_Poliza(c.m_Poliza),
    m_ValorCompra(c.m_ValorCompra),
    m_Siniestros(c.m_Siniestros)
{
}

// PREGUNTA 4: AgregarSiniestro de la clase CContrato

void CContrato::AgregarSiniestro(const CSiniestro& s) {
    this->m_Siniestros.AgregarObjeto(s.Clonar());
}

ostream &operator<<(ostream &os, CContrato &c) {
  os << c.GetDescripcion();
  return os;
}

CContrato::~CContrato()
{
  BorrarSiniestros();
}

void CContrato::BorrarSiniestros()
{
    this->m_Siniestros.Restart();
    while (this->m_Siniestros.TieneMas()) {
        delete this->m_Siniestros.GetActual();
    }
}


void CContrato::MostrarSiniestros(ostream& os)
{
  if (this->m_Siniestros.EstaVacia())
    os << "Contrato sin siniestros." << endl;
  else
  {
    this->m_Siniestros.GetPrimero()->Mostrar(os);
    while (this->m_Siniestros.TieneMas())
      this->m_Siniestros.GetActual()->Mostrar(os);
  }
}


// Necesaria para PREGUNTA 5

ostream& operator<<(ostream& os, CContrato& c) {
    os << c.GetDescripcion();
    return os;
}