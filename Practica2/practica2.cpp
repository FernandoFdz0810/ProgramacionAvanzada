#include <iostream>
#include <string>
#include "MemoryManager.h"
#include "utils.h"
#include "CMatFloat.h"

using namespace std;

int main(int argc, char* argv[])
{
	bool salir = false;
	CMatFloat matriz;
	matriz.Iniciar();
	//Opciones del menú
	char* opciones[] =
	{
		(char*)"Construir matriz 1D",
		(char*)"Construir matriz 2D",
		(char*)"Introducir matriz",
		(char*)"Mostrar matriz",
		(char*)"Destruir matriz",
		(char*)"Terminar"
	};

	int nOpciones = sizeof(opciones) / sizeof(char*);

	do
	{
		switch (CrearMenu(opciones, nOpciones))
		{
		case 1:
			cout << "Se va a crear matriz unidimensional.\n";
			cout << "Introduzca número de filas\n";
			matriz.CrearMatriz1D(LeerInt());
			break;
		case 2:
			if (!matriz.Existe())
			{
				cout << "Introduzca numero de filas y de columnas: \n";
				int nFilas = LeerInt();
				int nColumnas = LeerInt();
				matriz.CrearMatriz2D(nFilas, nColumnas);
				break;
			}
			break;
		case 3:
			matriz.Introducir();
			break;
		case 4:
			matriz.Mostrar();
			break;
		case 5:
			matriz.Destruir();
			break;
		case 6:
			salir = true;
			if (matriz.Existe())
				matriz.Destruir();
			break;
		}
	} while (!salir);

	MemoryManager::dumpMemoryLeaks();
}