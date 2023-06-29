#include "CSiniestro.h"
using namespace std;

// PREGUNTA 6: iniciar m_SigCodigo
int CSiniestro::m_SigCodigo = 1;




// PREGUNTA 10: CSiniestroNormal s("Rotura de tambor");

CSiniestro::CSiniestro(const string& Desc)
	: m_Codigo(m_SigCodigo++), m_Descripcion(Desc)
{
}






void CSiniestro::Mostrar(ostream& os) const
{
    float mCoste = GetCoste();
    os << " Codigo del siniestro: " << m_Codigo << endl
		<< " Descripcion de la averia: " << m_Descripcion << endl
		<< " Horas de mano de obra: " << m_HorasMO << endl
		<< " Coste de las piezas: " << m_CostePiezas << endl
		<< " Coste total de reparacion: " << mCoste << endl;
}