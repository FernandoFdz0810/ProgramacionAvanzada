// Práctica 5 Programacion Avanzada UAH
// Fernando Fernández Ortiz
// Miembros de una clase que son a su vez objetos de otra clase
#include "CFicha.h"

using namespace utils;

int main()
{
	CFicha* dinamico = nullptr;
	int opcion, edad, nHoras, nMinutos, nSegundos;
	string nombre, formato;
	bool Salir = false;

	string opciones_menu[] =
	{
		(string)"Crear una ficha",
		(string)"Visualizar ficha",
		(string)"Terminar",
	};

	const int num_opciones = sizeof(opciones_menu) / sizeof(string);
	enum op {Crear = 1, Visualizar, Terminar};

	do
	{
		switch (CUtils::CrearMenu(opciones_menu, num_opciones))
		{
		case Crear:
			if (dinamico != nullptr)
				delete dinamico;

			// Reservamos memoria dinámica para el objeto

			dinamico = new CFicha;

			// Proceso de introducir datos

			cout << "Nombre : "; CUtils::LeerDato(nombre);
			dinamico->AsignarNombre(nombre);
			cout << "Edad : "; CUtils::LeerDato(edad);
			dinamico->AsignarEdad(edad);

			// A continuacion se asigna hora nacio.

			do
			{
				cout << "Horas: "; CUtils::LeerDato(nHoras);
				cout << "Minutos: "; CUtils::LeerDato(nMinutos);
				cout << "Segundos: "; CUtils::LeerDato(nSegundos);
				cout << "Formato: "; CUtils::LeerDato(formato);
			} while (dinamico->AsignarNacio(nHoras, nMinutos, nSegundos, formato) != true);


			break;

		case Visualizar:
			
			if (dinamico == nullptr)
			{
				cout << "No hay ninguna ficha creada\n";
				break;
			}

			VisualizarFicha(*dinamico);
			system("pause");
			break;

		case Terminar:
			cout << "Saliendo del programa...\n";
			delete dinamico;
			Salir = true;
			break;
		}

	} while (Salir != true);

	MemoryManager::dumpMemoryLeaks();
	system("pause");

}