#if !defined (_CPOLINOMIO_H_)
#define _CPOLINOMIO_H_

#include "CTermino.h"
#include "CMonomio.h"
#include "MemoryManager.h"

using namespace std;

class CPolinomio
{
private:
	CTermino* m_pCabecera;

public:
	//Definir constructores
	//1. Constructor sin parametros que inicie el puntero a NULL
	CPolinomio();
	//2. Un constructor copia que copie un polinomio. Su parámetro debe ser una referencia a un objeto const. 
	//Implementar el constructor copia de forma que realice la misma iniciación del constructor sin parámetros, 
	//seguida de una llamada al operador de asignación indicado en el punto 7.
	CPolinomio(const CPolinomio& polinomio);
	//3. Constructor que reciba un coeficiente y un exponente para construir un polinomio con un solo término. 
	// El exponente debera tener el valor 0 por defecto. Si el coeficiente recibido es 0, la lista deberá dejarse vacía 
	// (con m_pCabecera apuntando a NULL).
	CPolinomio(double coeficiente, int exponente = 0);

	//4. Un constructor que reciba un vector<CMonomio> y construya un polinomio formado por los monomios contenidos
	// en dicho vector. Para ello puede utilizar la sobrecarga del operador de insecion especificado un poco mas adelante.

	CPolinomio(vector<CMonomio>& monomios);

	// 5. Un constructor que reciba un monomio para construir un polinomio con un solo termino. 
	// Si el coeficiente del monomio recibido es 0, la lista debe dejarse vacia( con m_pCabecera apuntando a NULL)

	CPolinomio(const CMonomio& monomio);

	//6. Un destructor que libere la memoria dinámica del polinomio

	~CPolinomio();

	//7. Operador de asignacion que copie un polinimo (utilizar sobrecargar del operador de insercion).
	//Tener en cuenta que el objeto destino puede contener datos anteriores. 
	//La memoria dinámica correspondiente a esos datos debe ser liberada antes de empezar a reservar memoria para copiar nuevos datos.
	CPolinomio& operator<<(const CPolinomio& polinomio);

	//La introducción de datos en un polinomio se hará mediante una nueva sobrecarga del operador de insercion. 

	CPolinomio& operator<<(const CMonomio& mono);


	//Funcion mostrar Poli
	void MostarPoli(ostream& os) const;

	//Muestra el mayor exponente de todos los miembros del polinomio
	int Grado() const;

	// Sobrecarga de operadores

	//Los operadores de comparacion se limitaran a comparar el grado de los polinomios

	bool operator==(const CPolinomio& polinomio);
	bool operator<(const CPolinomio& polinomio);
	bool operator>(const CPolinomio& polinomio);

	CPolinomio operator-() const;
	const CPolinomio operator+(const CPolinomio& polinomio);
	const CPolinomio operator-(const CPolinomio& polinomio);
	CPolinomio& operator+=(const CPolinomio& polinomio);
	CPolinomio& operator-=(const CPolinomio& polinomio);
	
	/*
	* El operador [] recibirá un número de exponente (int) 
	y devolverá el coeficiente (double) del término que tenga ese exponente.
	Si ningún término del polinomio tiene ese exponente, devolverá 0.
	*/

	double operator[](int exponente);

	/*
	El operador () recibirá un valor de la x del polinomio (double) y devolverá el valor del polinomio (double) para ese valor de x.
	Este operador servirá para convertir a los polinomios en funciones matemáticas.
	*/
	double operator()(float x);

	const CPolinomio operator*(const CPolinomio& polinomio);
	const CPolinomio operator*=(const CPolinomio& polinomio);



	CPolinomio& operator=(const CPolinomio& polinomio);



};

// El operador de insercion sirve para enviar un polinomio a un flujo, llamará a la funcion MostrarPoli

ostream& operator<<(ostream& os, const CPolinomio& Poli);

#endif
