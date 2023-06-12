#if !defined(_CPOLINOMIO_H_)
#define _CPOLINOMIO_H_

#include "CMonomio.h"
//#include "CTermino.h"

#include "MemoryManager.h"

class CPolinomio
{
private:
	vector<CMonomio> m_monomios; // de mayor a menor grado
public:
	CPolinomio() {} //1) Un constructor sin parámetros que inicie el puntero m_pCabecera a NULL.(definir aquí también?)

	//2) Un constructor copia que copie un polinomio.Su parámetro debe ser una
	//referencia a un objeto const.Implementar el constructor copia de forma que
	//realice la misma iniciación del constructor sin parámetros, seguida de una
	//llamada al operador de asignación indicado en el punto 7.
	//CPolinomio(const CPolinomio& polinomio);

	//3) Un constructor que reciba un coeficiente y un exponente para construir un
	//polinomio con un sólo término.El exponente deberá tener el valor 0 por defecto.
	//	Si el coeficiente recibido es 0, la lista deberá dejarse vacía(con m_pCabecera apuntando a NULL).
	CPolinomio(double coeficiente, int exponente = 0);	//Constructor polinomio de un solo termino

	//4) Un constructor que reciba un vector<CMonomio> y construya un polinomio
	//formado por los monomios contenidos en dicho vector.Para ello puede utilizar
	//la sobrecarga del operador de inserción especificado un poco más adelante.
	CPolinomio(vector<CMonomio>& monomios);					//Constructor polinomio a partir de un vetor de la clase CMonomio

	//5) Un constructor que reciba un monomio para construir un polinomio con un sólo
	//término.Si el coeficiente del monomio recibido es 0, la lista deberá dejarse vacía(con m_pCabecera apuntando a NULL).
	CPolinomio(const CMonomio& monomio);				//Constructor polinomio a partir  de un monomio de 1 solo termino

	//6) Un destructor que libere la memoria dinámica del polinomio.
	//~CPolinomio();										//Destructor

	void MostrarPoli(ostream& os) const;

	//7) Un operador de asignación que copie un polinomio(utilice la sobrecarga del
	//operador de inserción especificado a continuación).Tener en cuenta que el
	//objeto destino puede contener datos anteriores.La memoria dinámica
	//correspondiente a esos datos debe ser liberada antes de empezar a reservar
	//memoria para copiar los nuevos datos.
	CPolinomio& operator<<(const CPolinomio& polinomio);	//operador de asignacion polinomio
	CPolinomio& operator<<(const CMonomio& mono);	//operador de asignacion monomio

	int Grado() const;					//muestra el maoyr exponente de todos los miembros del polinomio

	//Sobrecarga de operadores
	//CPolinomio& operator=(const CPolinomio& polinomio);

	bool operator==(const CPolinomio& polinomio);
	bool operator<(const CPolinomio& polinomio);
	bool operator>(const CPolinomio& polinomio);

	CPolinomio operator-() const;						//operador unario
	const CPolinomio operator+(const CPolinomio& polinomio);
	const CPolinomio operator-(const CPolinomio& polinomio);
	CPolinomio& operator+=(const CPolinomio& polinomio);
	CPolinomio& operator-=(const CPolinomio& polinomio);

	double operator[](int exponente);
	double operator()(float x);

	const CPolinomio operator*(const CPolinomio& polinomio);
	CPolinomio& operator*=(const CPolinomio& polinomio);

	
};
ostream& operator<<(ostream& os, const CPolinomio& Poli);
#endif