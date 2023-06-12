#include "MemoryManager.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

float** ConstruirMatriz(int nFilas, int nColumnas)
{
	int i, j; //Variables para bucle for en Asignación dinámica

	// Reservamos memoria dinámica para filas
	float** pp = (float**)malloc(sizeof(float*) * nFilas);
	if (pp == NULL)
	{
		printf("Error a la hora de asignar memoria dinámica\n");
		for (i = 0; i < nFilas; i++)
		{
			free(pp);
		}
		return NULL;
	}

	for (i = 0; i < nFilas; i++)
	{
		pp[i] = (float*)malloc(sizeof(float) * nColumnas);
		if (pp[i] == NULL)
		{
			printf("Error a la hora de asignar memoria dinámica en las columnas\n");
			for (i = 0; i < nColumnas; i++)
			{
				free(pp[i]);
			}
			return NULL;
		}

		else
		{
			for (j = 0; j < nColumnas; j++)
			{
				pp[i][j] = 0.0;
			}
		}
	}

	printf("\nSe ha creado una matriz bi-dimensional de %d filas y %d columnas", nFilas, nColumnas);

	// Una vez asignada la memoria dinámica, procedemos a inicializar la matriz a 0, en todos sus campos
	return pp;

	
}

void IntroducirDatos(MatFloat *matriz)
{
	int nFilas = matriz->nFilas;
	int nColumnas = matriz->nColumnas;

	
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
			printf("Introduce el valor para la Fila %d y la Columna %d: \n", nFilas, nColumnas);
			scanf_s("%f", &matriz->ppMatrizF[i][j]);
		}
	}
}

void Mostrar(MatFloat matriz)
{
	if (matriz.ppMatrizF == NULL)
	{
		printf("No existe matriz bi-dimensional, debe crearla\n\n");
		return;
	}

	for (int i = 0; i < matriz.nFilas; i++)
	{
		for (int j = 0; j < matriz.nColumnas; j++)
		{
			printf("p[%d][%d]: ", i, j);
			printf(" %2.f\n", matriz.ppMatrizF[i][j]);
		}
	}

	printf("\n");
}

void Destruir(MatFloat* matriz)
{
	float** pp = matriz->ppMatrizF;
	for (int i = 0; i < matriz->nFilas; i++)
	{
		free(pp[i]);

	}
	free(pp);
	matriz->ppMatrizF = NULL;
}