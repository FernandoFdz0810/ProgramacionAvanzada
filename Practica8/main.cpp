#include <iostream>
#include "CLista.h"
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "CEmpresa.h"
#include "utils.h"
#include "MemoryManager.h"
#include <fstream>
#include <cstdlib>
#include "Practica8/Practica8/Practica8/CIndiceIncorrecto.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{

        const char* OpMenu[] = { " 1. Vaciar() de CLista.",
                     " 2. Operador [] CLista.",
                     " 3. Constructor copia de CContrato.",
                     " 4. AgregarSiniestro() de CContrato.",
                     " 5. Operador << CCliente.",
                     " 6. m_pSigCodigo static.",
                     " 7. Presupuestar() de CSiniestro y derivadas",
                     " 8. AgregarContrato() de CCliente",
                     " 9. total += seguros[i]",
                     "10. Constructor CSiniestro y CSiniestroNormal",
                     "11. const_cast<CLista<T>*>(this)->",
                     "12. GetCoste()?",
                     "13. c.AgregarSiniestro()",
                     "14. Plantilla CEmpresa.",
                     "15. Guardar empresa.",
                     "16. Salir."
        };
        const int numopciones = sizeof(OpMenu) / sizeof(char*);
        int opcion = 0;

        do
        {
            opcion = CUtils::CrearMenu(OpMenu, numopciones);
            switch (opcion)
            {
            case 1:
            {
                // Crear una lista para después vaciarla
                CLista<string> miLista;
                string nombres[] = { "Javier", "Fernando", "Oscar", "Ismael", "Alicia",
                  "Sara", "Diego", "Carlos", "Manuel", "Alejandro" };

                // Agregar los nombres a la lista
                for (int i = 0; i < 10; i++)
                {
                    miLista.AgregarObjeto(nombres[i]);
                }

                // Mostrar la lista. Preveer execepción CIndiceIncorrecto.
                try
                {
                    for (int i = 0; i < 11; i++)
                    {
                        cout << miLista[i] << " ";
                    }
                }
                //Lanzar excepcion CIndiceIncorrecto
                catch (CIndiceIncorrecto& e)
                {
					cout << e.what() << endl;
				}


                // Vaciar la lista y verificar después que está vacía.
                miLista.Vaciar();
                cout << "La lista está vacía: " << (miLista.EstaVacia() ? "Sí" : "No") << endl;

                cout << "Respuestas a las preguntas: ..." << endl;
                cout << "No es necesario que la Clase CLista sea friend de CNodoLista . Debido a que la declaración friend class CLista<T> en CNodoLista.h indica que la clase CLista tiene acceso a los miembros privados de CNodoLista. ";
                system("pause");
                break;
            }
            case 2:
            {
                // Ejemplo operador [] con lista de enteros
                CLista<int> lista;
                // Crear un objeto lista que almacene 10 datos de tipo int
                for (int i = 1; i <= 10; i++) {
                    lista.AgregarObjeto(i);
                }

                // Sumar todos los números de la lista y provocar la excepción CIndiceIncorrecto
                int suma = 0;
                try {
                    for (int i = 0; i <= 10; i++) {
                        suma += lista[i];
                    }
                }
                catch (const CIndiceIncorrecto& e) {
                    cout << "Se produjo una excepción: " << e.what() << endl;
                }

                cout << "La suma de los números en la lista es: " << suma << endl;

                system("pause");
                break;
            }
            case 3: // Pregunta 1
            {
                // Crear e iniciar objeto CContrato a copiar
                CContrato original(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);
                // Rellenar objeto original
                TSituacion situacion = local;
                original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
                original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
                original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));
                cout << " CONTRATO ORIGINAL: " << endl << endl << original;

                cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
                CContrato copia(original);
                original = copia;
                cout << " CONTRATO ORIGINAL: " << copia << endl;
                system("pause");
                break;
            }
            case 4:
            {
                CContrato prueba(12345);
                // Agregar a "prueba" un siniestro urgente y otro normal
                prueba.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
                prueba.AgregarSiniestro(CSiniestroNormal("siniestro 2"));

                prueba.MostrarSiniestros();
                cout << endl;
                cout << "Respuestas a las preguntas: ..." << endl;
                cout << "Sí, es necesario que Clonar() sea virtual. La razón es que cuando se trabaja con polimorfismo y se tiene una clase base (CSiniestro) y varias clases derivadas (CSiniestroUrgente, CSiniestroNormal, etc.), si quieres utilizar el puntero de la clase base para crear copias de los objetos derivados, necesitas que la función Clonar() sea virtual.";
                system("pause");
                break;
            }
            case 5:
            {
                // Crear cliente
                CCliente cli("Juan");
                // Agregar un contrato con siniestro normal a cli
                CContrato* contrato = new CContrato(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);
                contrato->AgregarSiniestro(CSiniestroNormal("siniestro 1"));
                cli.AgregarContrato(*contrato);
                // Agregar un contrato con siniestro urgente a cli
                contrato = new CContrato(54321, "Prueba constructor copia", "11-01-16", 123456789, 987654321);
                contrato->AgregarSiniestro(CSiniestroUrgente(local, "siniestro 2"));
                cli.AgregarContrato(*contrato);

                

                // Mostrar datos
                cout << " Datos del cliente: \n" << endl << cli << endl;
                system("pause");

                cout << "Llamada explícita:\n";
                system("pause");
                break;
            }
            case 6:
            {
                cout << "Respuestas a las preguntas: ..." << endl;
                cout << "La inicializacion de la variable debe realizarse fuera de la definicion de la clase, en el archivo CSiniestro.cpp" << endl;
                cout << "La inicializacion de m_SigCodigo no es imprescindible, pero es recomendalbe para asegurar que el primer objeto de CSiniestro tenga un código inicial." << endl;
                cout << "Si no se realizara la inicialización, tendría un valor predeterminado '0' debido a la inicialización automática de variables estáticas." << endl;
                system("pause");
                break;
            }
            case 7:
            {
                CSiniestroUrgente MiSiniestroUrgente(internacional, "Siniestro Urgente Ejemplo");
                MiSiniestroUrgente.Presupuestar(7, 3);
                CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
                MiSiniestroNormal.Presupuestar(9, 4);

                cout << "Respuestas a las preguntas: ..." << endl;
                cout << "Si la variable m_Coste fuera declarada private, las clases derivadas no podrían acceder directamente a ella" << endl;
                cout << " lo que dificultaría o impediría la implementación correcta de la funcion Presupuestar en las clases derivadas CSiniestroNormal y CSiniestroUrgente." << endl;
                cout << " La función miembro GetCoste() si fuera declarada como private, no podría ser llamada desde las clases derivadas CSiniestroNormal y CSiniestroUrgente." << endl;
                system("pause");
                break;
            }
            case 8:
            {
                // Crear un cliente cli

                CCliente cli("Juan Perez", CContrato(1234, "Contrato 1", "2023-12-31", 9876, 5000));

                // Agregar a cli un contrato con siniestros
                CContrato contrato(5678, "Contrato 2", "2024-06-30", 5432, 8000);
                contrato.AgregarSiniestro(CSiniestroNormal("Rotura de tambor"));
                contrato.AgregarSiniestro(CSiniestroNormal("Fallo en el motor"));
                contrato.AgregarSiniestro(CSiniestroNormal("Daños por colisión"));
                cli.AgregarContrato(contrato);

                // Mostrar cli
                cout << cli << endl;

                system("pause");
                return 0;
            }
            case 9:
            {
                CCliente* seguros = new  CCliente[MAX_CLIENTES];

                // Agregar contratos aleatorios a la matriz seguros

                    // Agregar contratos aleatorios a la matriz seguros
                for (int i = 0; i < MAX_CLIENTES; i++) {
                    // Generar un número aleatorio para el contrato
                    int contrato = rand() % 1000; // Siendo rango de 0 a 999

                    // Asignar el contrato al cliente correspondiente
                    seguros[i].AgregarContrato(contrato);


                    // Contar el número total de contratos
                    long total = 0;
                    for (int i = 0; i < MAX_CLIENTES; i++)
                        total += seguros[i];
                    cout << "\n El numero total de contratos de los clientes asciende a: ";
                    cout << total << " contratos\n";
                    system("pause");
                    delete[] seguros;
                    break;
                }
            }
            case 10:
            {
                CSiniestroNormal s("Rotura de tambor");
                cout << endl;
                s.Mostrar(); cout << endl;

                cout << "Respuesta a la pregunta: ..." << endl;
                system("pause");
                break;
            }
            case 11:
            {
                cout << "Respuesta a la pregunta: ..." << endl;
                cout << "No es recomendable, eliminar el código. Const Cast se utiliza para eliminar la constancia de this." << endl;
                cout << "El hecho de que GetPrimero() sea constante indica que no deberia realizar modificaciones. Si se elimina el ´código sombreado" << endl;
                cout << "Se permite la modificacion del miembre m_Actual.";
                system("pause");
                break;
            }
            case 12:
            {
                cout << "Respuesta a la pregunta: ..." << endl;
                cout << "No es posible llamar a la funcion miembre GetCoste() desde Mostrar(). Se debe a que Get Coste() es no estática y no se puede llamar " << endl;
                cout << "Directamente dentro de una funcion miembro constante como Mostrar().";
                system("pause");
                break;
            }
            case 13:
            {
                CContrato c(12345, "Cafetera C1Z", "2/1/2016", 100, 1000);
                CSiniestroUrgente s(nacional, "Fallo general");
                c.AgregarSiniestro(s);

                cout << "Respuestas a las preguntas: ..." << endl;
                cout << "1º Se crea un objeto CContrato llamado c con los parametros indicados." << endl;
                cout << "2º. Se crea un objeto CSiniestroUrgente llamado s utilizando el constructor con los parametros indicados." << endl;
                cout << "3º. Se llama a la funcion AgregarSiniestro() de c pasandole como parametro el objeto s." << endl;
                cout << "El orden de las llamadas sería: " << endl;
                cout << "1º. Se llama al constructor de CContrato con los parametros indicados." << endl;
                cout << "2º. Se llama al constructor de CSiniestroUrgente con los parametros indicados." << endl;
                cout << "3º. Se llama a la funcion AgregarSiniestro del objeto c y se le pasa el objeto "s" como argumento" << endl;
                system("pause");
                break;
            }
            case 14:
            {
                CEmpresa<CCliente> empresa1;

                // Agregar elementos a la empresa
                CCliente cliente1("John Doe", 30);
                CCliente cliente2("Jane Smith", 25);
                empresa1.AgregarElemento(cliente1);
                empresa1.AgregarElemento(cliente2);

                // Crear empresa2 como copia de empresa1
                CEmpresa<CCliente> empresa2(empresa1); // constructor de copia

                // Mostrar la empresa2
                cout << "\nCLIENTES DE LA EMPRESA:\n" << endl;
                for (int i = 0; i < empresa2.Tamanyo(); i++)
                {
                    cout << empresa2[i] << endl; // Mostrar el contenido de empresa2 utilizando el operador de indexación
                }

                system("pause");
                break;
            }
            case 15:
            {
                // Crear empresa
                CEmpresa<CCliente> empresa1;

                // Rellenar empresa
                CCliente cliente1("John Doe", 30);
                CCliente cliente2("Jane Smith", 25);
                empresa1.AgregarElemento(cliente1);
                empresa1.AgregarElemento(cliente2);

                // Guardar los nombres en un fichero (escribir)
                std::ofstream archivo("clientes.txt");
                if (archivo.is_open())
                {
                    for (int i = 0; i < empresa1.Tamanyo(); i++)
                    {
                        archivo << empresa1[i].GetNombre() << '\n';
                    }
                    archivo.close();
                    cout << "\nCLIENTES DE LA EMPRESA GUARDADOS.\n";
                }
                else
                {
                    cout << "No se pudo abrir el archivo clientes.txt" << endl;
                }

                // Verificar la información almacenada en el fichero (leer)
                std::ifstream archivoMostrar("clientes.txt");
                if (archivoMostrar.is_open())
                {
                    std::string nombre;
                    cout << "\nCONTENIDO DEL FICHERO:\n" << endl;
                    while (std::getline(archivoMostrar, nombre))
                    {
                        cout << "Nombre: " << nombre << endl;
                    }
                    archivoMostrar.close();
                }
                else
                {
                    cout << "No se pudo abrir el archivo clientes.txt" << endl;
                }

                system("pause");
                break;
            }
            }
        }while (opcion < numopciones);

 
    MemoryManager::dumpMemoryLeaks();
    system("pause");
}

