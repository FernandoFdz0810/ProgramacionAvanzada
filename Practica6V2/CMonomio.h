#if !defined(_CMONOMIO_H_)
#define _CMONOMIO_H_

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class CMonomio
{
private:
	double m_dCoeficiente;
	int m_nExponente;
public:
	CMonomio(double dCoef = 0, int nExp = 0) : m_dCoeficiente(dCoef), m_nExponente(nExp) {} //constructor
	double GetCoef() const { return m_dCoeficiente; }
	int GetExp() const { return m_nExponente; }
	void SetCoef(double dCoef) { m_dCoeficiente = dCoef; }
	void SetExp(int nExp) { m_nExponente = nExp; }
	CMonomio operator-() const { return CMonomio(-m_dCoeficiente, m_nExponente); }
};
ostream& operator<<(ostream& os, const CMonomio& mono);

#endif