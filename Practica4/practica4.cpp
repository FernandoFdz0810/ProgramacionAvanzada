
#include "CHora.h"

using namespace utils;

int main(int argc, char* argv[])
{
	// Creación de un puntero dinámico iniciado a 0.
	CHora* dinamico = nullptr;

	bool Terminar = false;
	bool Terminar2 = false;
	char formato[20];

	int horas, minutos, segundos;
	
	char* opciones_menu[]
	{
		(char*)"Crear un objeto local",
		(char*)"Crear un objeto dinámico",
		(char*)"Constructor copia",
		(char*)"Operador de asignación",
		(char*)"Terminar",
	};

	int num_opciones = sizeof(opciones_menu) / sizeof(char*);
	enum op {Local = 1, Dinamico, Copia, Asignacion, Salir};
	do 
	{
		system("cls");
		switch (CUtils::CrearMenu(opciones_menu, num_opciones))
		{
			case Local:
			{
				char* opciones_menu2[]
				{
					(char*)"Con una hora predeterminada.",
					(char*)"Introduciendo la hora.",
					(char*)"Introduciendo la hora y los minutos.",
					(char*)"Introduciendo la horas, los minutos y los segundos.",
					(char*)"Introduciendo la horas, los minutos, los segundos y el formato.",
					(char*)"Volver al menú principal",
				};

				int num_opciones2 = sizeof(opciones_menu2) / sizeof(char*);
				enum op2 { Predeterminada = 1, Hora, Hora_Minutos, Hora_Minutos_Segundos, Hora_Completa, Volver };

				do
				{
					system("cls");
					switch (CUtils::CrearMenu(opciones_menu2, num_opciones2))
					{
					case Predeterminada:
					{

						CHora matriz_hora;
						VisualizarHora(matriz_hora);
						system("pause");

						break;
					}
					case Hora:
					{
						while (true)
						{
							cout << "Introduzca la hora que desea, por defecto el formato es 24 HORAS: \n";
							cout << "Horas: "; CUtils::LeerDato(horas);

							// Se llama al contructor por defecto, pasandole por defecto solo un argumento, el de horas.

							CHora matriz_hora(horas);

							// Se debe comprobar si la hora es correcta

							if (matriz_hora.EsHoraCorrecta())
							{
								//Si es correcta, se procede a visualizar la hora.
								VisualizarHora(matriz_hora);
								system("pause");
								break;
							}
						}
						break;

					}
					case Hora_Minutos:
					{
						while (true)
						{
							cout << "Introduzca la hora que desea, por defecto el formato es 24 HORAS: \n";
							cout << "Horas: "; CUtils::LeerDato(horas);
							cout << "Minutos: "; CUtils::LeerDato(minutos);
							CHora matriz_hora(horas, minutos);

							if (matriz_hora.EsHoraCorrecta())
							{
								// Si es correcta, se procede a visualizar la tarea
								VisualizarHora(matriz_hora);
								system("pause");
								break;
							}
						}
							
					
						break;
					}

					case Hora_Minutos_Segundos:
					{
						while (true)
						{
							cout << "Introduzca horas, minutos y segundos. El formato por defecto es 24 HORAS: \n";
							cout << "Horas: "; CUtils::LeerDato(horas);
							cout << "Minutos: "; CUtils::LeerDato(minutos);
							cout << "Segundos: "; CUtils::LeerDato(segundos);
							CHora matriz_hora(horas, minutos, segundos);

							if (matriz_hora.EsHoraCorrecta())
							{
								VisualizarHora(matriz_hora);
								system("pause");
								break;
							}
						}
						break;
					}

					case Hora_Completa:
					{
						cout << "Introduzca horas, minutos, segundos y formato\n";
						cout << "Horas: "; CUtils::LeerDato(horas);
						cout << "Minutos: "; CUtils::LeerDato(minutos);
						cout << "Segundos: "; CUtils::LeerDato(segundos);
						cout << "Formato: "; CUtils::LeerDato(formato);
						CHora matriz_hora(horas, minutos, segundos, formato);

						if (matriz_hora.EsHoraCorrecta())
						{
							VisualizarHora(matriz_hora);
							system("pause");
							break;
						}

						break;
					}

					case Volver:
						Terminar2 = true;
						break;

					}
				} while (Terminar2 != true);
			}

			case Dinamico:
				if (dinamico != nullptr)
					delete dinamico;

				while (true)
				{
					cout << "Introduzca horas, minutos, segundos y formato.\n";
					cout << "Horas: "; CUtils::LeerDato(horas);
					cout << "Minutos: "; CUtils::LeerDato(minutos);
					cout << "Segundos: "; CUtils::LeerDato(segundos);
					cout << "Formato: "; CUtils::LeerDato(formato);
					
					// Una vez solicitado los datos, se procede a crear el objeto dinámicamente. 

					dinamico = new CHora(horas, minutos, segundos, formato);

					if (dinamico->EsHoraCorrecta())
					{
						VisualizarHora(*dinamico);
						system("pause");
						break;
					}

					else //En caso de que se haya introducido el formato erroneo EsHoraCorrecta() devuelve false
					{
						delete dinamico;
					}
				}

				break;

			case Copia:
			{
				if (dinamico == nullptr)
					cout << "Matriz dinamica no creada, no se puede completar la copia\n";

				CHora dinamico_copia(*dinamico);
				VisualizarHora(dinamico_copia);
				system("pause");
				break;
			}


			case Asignacion:
			{
				if (dinamico == nullptr)
				{
					cout << "Objeto dinamico no creado. \n";
					system("pause");
					break;
				}

				while (true)
				{
					CHora asignacion; // Se inicializa un objeto con sus valores a 0 por defecto
					asignacion = *dinamico; // Se realiza una copía de los parámetros del objeto dinámico al recien creado 
					VisualizarHora(asignacion);
					system("pause");
					break;
				}

				break;

			case Salir:
				cout << "Saliendo del programa...\n";
				Terminar = true;
				break;
			}
		}

	} while (Terminar != true);

	MemoryManager::dumpMemoryLeaks();

}