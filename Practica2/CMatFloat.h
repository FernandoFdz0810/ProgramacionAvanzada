#pragma once

class CMatFloat // Creación de la clase.
{
	// Datos privados de la clase
private :
	float** m_ppDatosF; // Apunta a los datos de la matriz
	int m_nFilas; // Número de filas
	int m_nColumnas; // Número de columna

// Métodos (funciones miembro) de la clase

public:
	void Iniciar();
	// Será invocada cada vez que se defina un objeto
	// Pone m_ppDatosF a NULL y m_nFilas y m_nColumnas a 0.

	void CrearMatriz2D(int nFilas, int nColumnas);
	//Asigna memoria a una matriz dinámica cuyas dimensiones vienen 
	//dadas por los parámetros de tipo entero que se le pasan y verifica que
	// la asignación fue correcta (No deben quedar lagunas de memoria) 
	//Pone la matriz a 0. Asigna a los datos miembro m_nFilas y m_nColumnas los 
	//valores adecuados.

	void CrearMatriz1D(int nElementos);
	//Será implementado en funcion de CrearMatriz2D, es decir, 
	//particularizando para un número de filas igual a uno.

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

