#if !defined(_CTERMINO_H_)
#define _CTERMINO_H_

#include <iostream>
#include "CMonomio.h"

using namespace std;

class CTermino
{
private:
	CMonomio m_Monomio; // Monomio contenido en el termino
	CTermino* m_pSig; // Puntero al siguiente termino

public:
	// Constructores
	// Constructor por omision
	CTermino(double coeficiente = 0, int exponente = 0, CTermino* siguiente = NULL) : m_Monomio(coeficiente, exponente), m_pSig(siguiente) {};
	// Constructor copia
	CTermino(const CMonomio& monomio, CTermino* sig = NULL) : m_Monomio(monomio), m_pSig(sig) {};
	// Constructor copia
	CTermino(const CTermino& termino)
	{
		*this = termino;
	}

	// Metodos get
	double GetCoef() const { return m_Monomio.GetCoef(); };
	int GetExp() const { return m_Monomio.GetExp(); };
	CMonomio GetMono() const {
		return m_Monomio;
	}
	CTermino* GetSig() const { return m_pSig; }

	//Metodos Set
	void SetCoef(double dCoef) { m_Monomio.SetCoef(dCoef); }
	void SetExpo(int nExp) { m_Monomio.SetExp(nExp); }
	void SetMono(const CMonomio& mono) { m_Monomio = mono; }
	void SetSig(CTermino* pSig) { m_pSig = pSig; }

};

#endif