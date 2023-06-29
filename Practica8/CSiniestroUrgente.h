#if !defined(_SINIESTROURGENTE_H)
#define _SINIESTROURGENTE_H

#include "CSiniestro.h"
#include <iostream>
#include <string>

using namespace std;

enum TSituacion
{
  local, nacional, internacional
};

class CSiniestroUrgente : public CSiniestro
{
private:
  TSituacion m_Situacion;
  static float m_Recargo;
  static float m_CosteHoraMO;

public:
  CSiniestroUrgente(TSituacion s, const std::string& Desc = "Sin Descripcion");

  void Presupuestar(float Horas = 0.5f, float Piezas = 0);
  void Mostrar(std::ostream & os = std::cout) const;
  CSiniestroUrgente* Clonar() const;
  float GetPresupuesto() const;

  ~CSiniestroUrgente();

  friend ostream& operator<<(ostream& os, const CSiniestro& sin);
};

ostream& operator<<(ostream& os, const TSituacion &s);
#endif