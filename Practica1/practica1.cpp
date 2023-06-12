#include "MemoryManager.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{

	int opcion = 0;
	float** pp; // Variable para asignar dirección memoria inicio a Matriz
	struct MatFloat matriz; //Desclaramos a la estructura MatFloat como matriz
	matriz.nFilas = NULL;
	matriz.nColumnas = NULL;
	matriz.ppMatrizF = NULL;

	do
	{
		printf("\n");
		printf("Escoja una opcion: \n");
		printf("\t1.Construir Matriz\n");
		printf("\t2.Introducir Matriz\n");
		printf("\t3.Volcar Matriz\n");
		printf("\t4.Destruir Matriz\n");
		printf("\t5.Terminar\n");
		printf("Opcion: ");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:

			system("cls"); //Limpiamos pantalla
			if (matriz.ppMatrizF == NULL)
			{
				do
				{
					printf("Escoja el número de columnas: ");
					scanf_s("%d", &matriz.nColumnas);
					while (getchar() != '\n');
				} while (matriz.nColumnas <= 0);

				do
				{
					printf("Escoja el número de filas: ");
					scanf_s("%d", &matriz.nFilas);
					while (getchar() != '\n');
				} while (matriz.nFilas <= 0);
			}

			else
			{
				printf("Ya existe una matriz dinámica creada, debe eliminarla primero\n\n");
				break;
			}

			pp = ConstruirMatriz(matriz.nFilas, matriz.nColumnas);
			matriz.ppMatrizF = pp;
			break;

		case 2:
			if (matriz.ppMatrizF == NULL)
			{
				printf("La matriz no existe. Debe crear una primero\n\n");
				break;
			}

			else
			{
				IntroducirDatos(&matriz);
				break;
			}

		case 3:
			if (matriz.ppMatrizF == NULL)
			{
				printf("No existe matriz dinámica, debe crearla primero\n");
				break;
			}
			else
				Mostrar(matriz);

			break;

		case 4:
			Destruir(&matriz);
			break;
		}
	} while (opcion != 5);

	MemoryManager::dumpMemoryLeaks();
	
}