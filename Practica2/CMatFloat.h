#pragma once

class CMatFloat // Creaci�n de la clase.
{
	// Datos privados de la clase
private :
	float** m_ppDatosF; // Apunta a los datos de la matriz
	int m_nFilas; // N�mero de filas
	int m_nColumnas; // N�mero de columna

// M�todos (funciones miembro) de la clase

public:
	void Iniciar();
	// Ser� invocada cada vez que se defina un objeto
	// Pone m_ppDatosF a NULL y m_nFilas y m_nColumnas a 0.

	void CrearMatriz2D(int nFilas, int nColumnas);
	//Asigna memoria a una matriz din�mica cuyas dimensiones vienen 
	//dadas por los par�metros de tipo entero que se le pasan y verifica que
	// la asignaci�n fue correcta (No deben quedar lagunas de memoria) 
	//Pone la matriz a 0. Asigna a los datos miembro m_nFilas y m_nColumnas los 
	//valores adecuados.

	void CrearMatriz1D(int nElementos);
	//Ser� implementado en funcion de CrearMatriz2D, es decir, 
	//particularizando para un n�mero de filas igual a uno.

	void Introducir();
	//Establece los elementos de la matriz con los valores que se introducen por teclado.
	// Valida los datos introducidos.

	void Mostrar();
	//Muesta los datos contenidos en la matriz. 
	// Motrar una fila debajo de otra, si procede.

	void Destruir();
	//Libera la memoria ocupada por los datos y llama a Iniciar().

	bool Existe();
	//Devuelve true si m_ppDatosF es distinto de NULL
	// la matriz existe, en otro caso, devuelve false.
};

