#include"CHora.h"
#include"utils.h"
#include <string>
using namespace std;

int main()
{
	CHora matriz;
	int opcion;
	matriz.Iniciar();

	int nHoras, nMinutos, nSegundos;
	string formato;

	string opciones_menu[] =
	{
		(string)"Introducir Hora",
		(string)"Visualizar Hora",
		(string)"Terminar"
	};

	const int num_opciones = sizeof(opciones_menu)/sizeof(string);
	enum op { Introducir = 1, Visualizar, Terminar };

	do {
		opcion = CrearMenu(opciones_menu, num_opciones);

		switch (opcion)
		{
		case Introducir:
			do {
				cout << "\n Establecer hora: Horas, Minutos, Segundos y Formato" << endl;
				nHoras = LeerInt();
				nMinutos = LeerInt();
				nSegundos = LeerInt();
				LeerCadena(formato, strlen("24 HORAS") + 1);

			} while (matriz.AsignarHora(nHoras, nMinutos, nSegundos, formato) != true); // resuelve falla al pedir hora

			break;


		case Visualizar:
			VisualizarHora(matriz);
			system("pause");
			break;
	

		case Terminar:
			cout << "\n Saliendo del programa..." << endl;
			matriz.Destruir();
			break;
		}

	} while (opcion != Terminar);

	MemoryManager::dumpMemoryLeaks();
	system("pause");
}