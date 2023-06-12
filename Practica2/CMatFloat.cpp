#include "CMatFloat.h"
#include "utils.h"
#include <cstddef>
#include <iostream>

using namespace std;

void CMatFloat::Iniciar()
{
	m_ppDatosF = NULL;
	m_nColumnas = 0;
	m_nFilas = 0;
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	int i, j;
	//Reservamos memoria dinámica para el número de filas
	m_nColumnas = nColumnas;
	m_nFilas = nFilas;
	m_ppDatosF = new (nothrow) float* [m_nFilas];
	if (m_ppDatosF == 0)
	{
		cout << "Insuficiente espacio de memoria\n";
		Destruir();
		return;
	}

	for (i = 0; i < nFilas; i++)
	{
		// Asignamos memoria dinámica para la columnas
		m_ppDatosF[i] = new(nothrow) float[m_nColumnas];
		if (m_ppDatosF[i] == 0)
		{
			cout << "Insuficiente espacio de memoria\n";
			cout << "Liberando memoria\n";
			// Si falla debemos liberar la memoria antes de salir
			Destruir();
		}

		else
		{
			for (j = 0; j < m_nColumnas; j++)
			{
				m_ppDatosF[i][j] = 0.0;
			}
		}


	}


	if (nColumnas == 1)
	{
		cout << "Se ha creado una matriz unidimensional de " << m_nFilas << "filas\n";
	}
	else
		cout << "Se ha creado una matriz dinámica de " << m_nFilas << "filas y " << m_nColumnas << "columnas\n";
	
}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	CMatFloat::CrearMatriz2D(nElementos, 1);
}

void CMatFloat::Introducir()
{
	if (!CMatFloat::Existe())
	{
		cout << "No existe la matriz unidimensional o bidimensional, debe crear una antes\n";
	}

	else
	{
		int i, j;
		for (i = 0; i < m_nFilas; i++)
		{
			for (j = 0; j < m_nColumnas; j++)
			{
				cout << "Introduzca el dato para la posición: [" << i + 1 << "][" << j + 1 << "]: ";
				m_ppDatosF[i][j] = LeerFloat();
			}
		}
	}
}

void CMatFloat::Mostrar()
{
	if (!CMatFloat::Existe())
	{
		cout << "No existe la matriz unidimensional o bidimensional, debe crear una antes\n";
	}

	else
	{
		int i, j;
		for (i = 0; i < m_nFilas; i++)
		{
			for (j = 0; j < m_nColumnas; j++)
			{
				cout << "[" << i + 1 << "][" << j + 1 << "]:" << m_ppDatosF[i][j] << "\n";
			}
		}
	}
}

void CMatFloat::Destruir()
{
	if (!CMatFloat::Existe())
	{
		cout << "No existe la matriz unidimensional o bidimensional, debe crear una antes\n";
	}

	else
	{
		int i;
		for (i = 0; i < m_nFilas; i++)
		{
			delete[] m_ppDatosF[i];
			// Liberamos memoria para las columnas
		}

		// Liberamos memoria para las filas
		delete[] m_ppDatosF;

		cout << "\nLa matriz ha sido eliminada\n";
		Iniciar();
	}
}

bool CMatFloat::Existe()
{
	if (m_ppDatosF == NULL)
		return false;
	else
		return true;
}