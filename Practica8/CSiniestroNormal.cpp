#include "CSiniestroNormal.h"
#include "MemoryManager.h"
using namespace std;

float CSiniestroNormal::m_CosteHoraMO = 2.5;

// PREGUNTA 10

// Implementa las funciones que se llaman cuando se ejecuta la siguiente sentencia: CSinisetroNormal s("Rotura de tambor");
CSiniestroNormal::CSiniestroNormal(const string& Desc)
	: CSiniestro(Desc)
{

}

CSiniestroNormal* CSiniestroNormal::Clonar() const
{
  return 	new CSiniestroNormal(*this);
}

void CSiniestroNormal::Mostrar(ostream& os) const {
	os << *this << "\n";
}

// PREGUNTA 7
void CSiniestroNormal::Presupuestar(float Horas, float Piezas)
{
  m_HorasMO = Horas;
  m_CostePiezas = Piezas;
  m_Coste = m_HorasMO * m_CosteHoraMO + m_CostePiezas;
}

float CSiniestroNormal::GetPresupuesto() const
{
  return m_Coste;
}

ostream& operator<<(ostream& os, const CSiniestro& sin) {
	os << "{\"codigo\":\"" << sin.GetCodigo()
		<< "\",\"presupuesto\":\"" << sin.GetPresupuesto() << "\"}";
	return os;
}
