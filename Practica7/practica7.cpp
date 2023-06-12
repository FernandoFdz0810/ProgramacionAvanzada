#include"registro.h"

//#define NREGISTROS 3

using namespace utils;

int main()
{	
	{
		//CRegistroDiario registro(NREGISTROS);
		//CRegistroDiario copia_registro(NREGISTROS);

		//CRegistroDiario rdNuevo(registro); //Comprobación constructor copia

		int nHoras, nMinutos, nSegundos, edad, nAntiguedad, n_regs;
		string formato, nombre, sCategoria, dni, busqueda;

		cout << "\n Introduzca el numero maximo de personas a registrar: ";
		CUtils::LeerDato(n_regs);
		cout << endl << "\n Registro creado con un maximo de " << n_regs << " personas." << endl;
		CRegistroDiario registro(n_regs);
		CRegistroDiario copia_registro(n_regs);

		int opcion;

		string opciones_menu[] =
		{
			(string)"Introducir empleado.",
			(string)"Introducir cliente.",
			(string)"Buscar por nombre.",
			(string)"Mostrar registro diario.",
			(string)"Mostrar empleados.",
			(string)"Copia de seguridad del registro diario.",
			(string)"Restaurar copia de seguridad.",
			(string)"Salir.",
		};

		const int num_opciones = sizeof(opciones_menu) / sizeof(string);
		enum op { IntroducirEmpleado = 1, IntroducirCliente, Buscar, MostrarRegistro, MostrarEmpleado, CopiaSeg, Rest_CopiaSeg, Salir };

		do
		{

			opcion = CUtils::CrearMenu(opciones_menu, num_opciones);

			switch (opcion)
			{
			case IntroducirEmpleado:
			{

				//CEmpleado empleado;

				if (registro.RegistroLLeno() != true)
				{
					cout << "\n Insertar Nombre: "; CUtils::LeerDato(nombre);

					do {
						cout << "\n Insertar edad: "; CUtils::LeerDato(edad);

						if (edad < 0)
							cout << "\n ERROR: Edad incorrecta, introduzca de nuevo la edad." << endl;

					} while (edad < 0);

					cout << "\n Insertar Categoria: "; CUtils::LeerDato(sCategoria);


					do {
						cout << "\n Insertar Antiguedad: "; CUtils::LeerDato(nAntiguedad);

						if (nAntiguedad < 0)
							cout << "\n ERROR: Antiguedad incorrecta, introduzca de nuevo la antiguedad." << endl;

					} while (nAntiguedad < 0);

					CEmpleado empleado(sCategoria, nAntiguedad, nombre, edad); // iniciamos CEmpleado con nuevos datos

					do {
						cout << "\n Establecer hora: Horas, Minutos, Segundos y Formato" << endl;
						cout << "\n Horas: "; CUtils::LeerDato(nHoras);
						cout << " Minutos: "; CUtils::LeerDato(nMinutos);
						cout << " Segundos: "; CUtils::LeerDato(nSegundos);
						cout << " Formato: "; CUtils::LeerDato(formato);

					} while (empleado.AsignarNacio(nHoras, nMinutos, nSegundos, formato) != true);

					registro.AgregarPersona(&empleado); //añadimos nueva ficha


					cout << "\n Nuevo empleado registrado." << endl;
					system("pause");
				}
				else
				{
					cout << "\n ERROR: Registro lleno." << endl;
					system("pause");
					break;
				}

				break;
			}
			case IntroducirCliente:
			{
				if (registro.RegistroLLeno() != true)
				{
					//CCliente cliente;
					cout << "Introducir DNI: "; CUtils::LeerDato(dni);

					//Creo que este metodo es innecesario ya que al llamar al constructor, se asigna automaticamente el DNI. COMPROBAR
					//cliente.SetDNI(dni);

					cout << "\n Insertar Nombre: "; CUtils::LeerDato(nombre);

					do {
						cout << "\n Insertar edad: "; CUtils::LeerDato(edad);

						if (edad < 0)
							cout << "\n ERROR: Edad incorrecta, introduzca de nuevo la edad." << endl;

					} while (edad < 0);

					CCliente cliente(dni, nombre, edad);

					do {
						cout << "\n Establecer hora: Horas, Minutos, Segundos y Formato" << endl;
						cout << "\n Horas: "; CUtils::LeerDato(nHoras);
						cout << " Minutos: "; CUtils::LeerDato(nMinutos);
						cout << " Segundos: "; CUtils::LeerDato(nSegundos);
						cout << " Formato: "; CUtils::LeerDato(formato);

					} while (cliente.AsignarNacio(nHoras, nMinutos, nSegundos, formato) != true);

					registro.AgregarPersona(&cliente); //El metodo agregar persona esta agregando bien al objeto CCliente?????

					cout << "\n Nuevo cliente registrado." << endl;
					system("pause");
				}

				else
				{
					cout << "\n ERROR: Registro lleno." << endl;
					system("pause");
					break;
				}

				break;
			}
			case Buscar:
			{
				cout << "Introduzca el nombre a encontrar: "; CUtils::LeerDato(busqueda);

				try 
				{
					registro.EncontrarPorNombre(busqueda);
				}
				catch (invalid_argument& e) {
					cout << e.what() << endl;
				}

			}
			break;
			case MostrarRegistro:
			{
				// Muestra empleados y clientes guardados en el registro
				registro.VisualizarRegistro();
				
			}
			break;
			case MostrarEmpleado:
			{	
				registro.VisualizarEmpleados();
			}
			break;
			case CopiaSeg:
			{
				if (registro[0] == NULL)
				{
					cout << "\n ERROR: No hay registro." << endl;
					system("pause");
					break;
				}

				if (copia_registro[0] == NULL)
				{
					copia_registro = registro;
					cout << "\n Copia de seguridad registrada." << endl;
				}
				else
					cout << "\n ERROR: Ya existe una copia de seguridad." << endl;

				system("pause");
				break;
			}
			case Rest_CopiaSeg:
			{
				if (copia_registro[0] == NULL)
				{
					cout << "\n ERROR: No existe una copia de seguridad." << endl;
					system("pause");
					break;
				}
				else
				{
					registro = copia_registro;
					CRegistroDiario aux(n_regs);
					copia_registro = aux;	//Destrucción copia_registro //copia_registro = NULL;?
					cout << "\n Copia restaurada." << endl;
				}

				system("pause");
				break;
			}
			case Salir:
				break;
			}
		} while (opcion != Salir);

	}

	MemoryManager::dumpMemoryLeaks();
	system("pause");
}