#include"CHora.h"

using namespace utils;

int main()
{
	CHora* dinamico = nullptr;
	int opcion, opcion1;

	int nHoras, nMinutos, nSegundos;
	string formato; //Falla en formato si es superior al final

	string opciones_menu[] =
	{
		(string)"Crear un objeto local",
		(string)"Crear un objeto dinamicamente",
		(string)"Constructor copia",
		(string)"Operador de asignacion",
		(string)"Terminar"
	};

	const int num_opciones = sizeof(opciones_menu) / sizeof(string);
	enum op { Local = 1, Dinamico, Copia, Operador, Terminar };

	do {
		opcion = CUtils::CrearMenu(opciones_menu, num_opciones);

		switch (opcion)
		{
		case Local: 
		{
			string opciones_menu1[] =
			{
				(string)"Con una hora predeterminada",
				(string)"Introduciendo la hora",
				(string)"Introduciendo la hora y los minutos",
				(string)"Introduciendo la horas, los minutos y los segundos",
				(string)"Introduciendo la hora ,los minutos ,los segundos y el formato",
				(string)"Volver al menu principal"
			};

			const int num_opciones1 = sizeof(opciones_menu1) / sizeof(string);
			enum op1 { Predeterminado = 1, Hora, H_M, H_M_S, H_M_S_F, Terminar };

			do {
				opcion1 = CUtils::CrearMenu(opciones_menu1, num_opciones1);

				switch (opcion1)
				{
				case Predeterminado:
				{
					CHora hora;
					VisualizarHora(hora);

					break;
				}
				case Hora:
				{
					while (true)
					{
						cout << "\n Establecer hora: Horas" << endl;
						cout << "\n Horas: "; CUtils::LeerDato(nHoras);
						CHora hora(nHoras);

						if (hora.EsHoraCorrecta())
						{
							VisualizarHora(hora);
							break;
						}
						else
							cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;

						system("pause");
					}

					break;
				}
				case H_M:
				{
					while (true)
					{
						cout << "\n Establecer hora: Horas y Minutos" << endl;
						cout << "\n Horas: "; CUtils::LeerDato(nHoras);
						cout << " Minutos: "; CUtils::LeerDato(nMinutos);
						CHora hora(nHoras, nMinutos);

						if (hora.EsHoraCorrecta())
						{
							VisualizarHora(hora);
							break;
						}
						else
							cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;

						system("pause");
					}

					break;
				}
				case H_M_S:
				{
					while (true)
					{
						cout << "\n Establecer hora: Horas, Minutos y Segundos" << endl;
						cout << "\n Horas: "; CUtils::LeerDato(nHoras);
						cout << " Minutos: "; CUtils::LeerDato(nMinutos);
						cout << " Segundos: "; CUtils::LeerDato(nSegundos);
						CHora hora(nHoras, nMinutos, nSegundos);

						if (hora.EsHoraCorrecta())
						{
							VisualizarHora(hora);
							break;
						}
						else
							cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;

						system("pause");
					}

					break;
				}
				case H_M_S_F:
				{
					while (true)
					{
						cout << "\n Establecer hora: Horas, Minutos, Segundos y Formato" << endl;
						cout << "\n Horas: "; CUtils::LeerDato(nHoras);
						cout << " Minutos: "; CUtils::LeerDato(nMinutos);
						cout << " Segundos: "; CUtils::LeerDato(nSegundos);
						cout << " Formato: "; CUtils::LeerDato(formato);
						CUtils::ConverMayus(formato);
						CHora hora(nHoras, nMinutos, nSegundos, formato);

						if (hora.EsHoraCorrecta())
						{
							VisualizarHora(hora);
							break;
						}
						else
							cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;

						system("pause");
					}

					break;
				}
				case Terminar:
					break;


				}
			} while (opcion1 != Terminar);

			break;
		}
		case Dinamico:
		{
			if (dinamico != nullptr)
				delete dinamico;

			while (true)
			{
				cout << "\n Establecer hora: Horas, Minutos, Segundos y Formato" << endl;
				cout << "\n Horas: "; CUtils::LeerDato(nHoras);
				cout << " Minutos: "; CUtils::LeerDato(nMinutos);
				cout << " Segundos: "; CUtils::LeerDato(nSegundos);
				cout << " Formato: "; CUtils::LeerDato(formato);
				CUtils::ConverMayus(formato);
				dinamico = new CHora(nHoras, nMinutos, nSegundos, formato);

				if (dinamico->EsHoraCorrecta())
				{
					VisualizarHora(*dinamico);
					break;
				}
				else
				{
					cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;
					delete dinamico;
				}

				system("pause");
			}
			break;
		}
		case Copia:
		{
			if (dinamico == nullptr)	//check
			{
				cout << "\n ERROR: No se ha encontrado el objeto dinamico." << endl;
				system("pause");
				break;
			}

			CHora dinamico_copia(*dinamico);
			VisualizarHora(dinamico_copia);
			break;
		}
		case Operador:
		{
			if (dinamico == nullptr)	//check
			{
				cout << "\n ERROR: No se ha encontrado el objeto dinamico." << endl;
				system("pause");
				break;
			}

			CHora dinamico_asignacion;
			dinamico_asignacion = *dinamico;
			VisualizarHora(dinamico_asignacion);
			break;
		}
		case Terminar:
			cout << "\n Saliendo del programa..." << endl;
			delete dinamico;
			break;
		}

	} while (opcion != Terminar);

	MemoryManager::dumpMemoryLeaks();
	system("pause");
}