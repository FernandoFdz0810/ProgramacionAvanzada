#include "CSiniestroUrgente.h"
#include "MemoryManager.h"
using namespace std;

float CSiniestroUrgente::m_Recargo = 5;
float CSiniestroUrgente::m_CosteHoraMO = 3.5;

CSiniestroUrgente::CSiniestroUrgente(TSituacion s, const std::string& Desc)
  : CSiniestro(Desc), m_Situacion(s)
{
    this->m_Situacion = s;
    this->m_Descripcion = Desc;
}

CSiniestroUrgente* CSiniestroUrgente::Clonar() const
{
  return new CSiniestroUrgente(*this);
}

void CSiniestroUrgente::Mostrar(ostream &os) const
{
  CSiniestro::Mostrar(os);
  os << " Tipo de cobertura: " << m_Situacion << endl
    << " Recargo por urgencia: " << m_Recargo << endl
    << " Coste hora de mano de obra: " << m_CosteHoraMO << endl << endl;
}

// PREGUNTA 7
void CSiniestroUrgente::Presupuestar(float Horas, float Piezas)
{
  m_HorasMO = Horas;
  m_CostePiezas = Piezas;
  m_Coste = m_CosteHoraMO * m_HorasMO + m_CostePiezas + m_Recargo;
}

float CSiniestroUrgente::GetPresupuesto() const
{
  return m_Coste;
}

ostream& operator<<(ostream& os, const CSiniestroUrgente& sin) {
  os << "{\"codigo\":\"" << sin.GetCodigo()
	<< "\",\"presupuesto\":\"" << sin.GetPresupuesto() << "\"}";
  return os;
}

ostream& operator<<(ostream& os, const TSituacion& s) {
    switch (s) {
    case TSituacion::internacional: {
        os << "internacional";
        break;
    }
    case TSituacion::nacional: {
        os << "nacional";
        break;
    }
    case TSituacion::local: {
        os << "local";
        break;
    }
    }
    return os;
}

CSiniestroUrgente::~CSiniestroUrgente()
{
}