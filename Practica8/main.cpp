#include <iostream>
#include "CLista.h"
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "CEmpresa.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
    {
        char* OpMenu[] = { " 1. Vaciar() de CLista.",
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
                string nombres[] = { "Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
                  "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10" };
                // Rellenar la lista con nombres
                for (int i = 0; i < 10; i++) {
                    miLista.Agregar(nombres[i]);
                }

                // Mostrar la lista. Prever excepción CIndiceIncorrecto.
                try {
                    for (int i = 0; i <= miLista.ObtenerUltimoIndice(); i++) {
                        cout << miLista[i] << endl;
                    }
                }
                catch (CIndiceIncorrecto& e) {
                    cout << e.GetMensaje() << endl;
                }

                // Vaciar la lista y verificar después que está vacía.
                miLista.Vaciar();
                if (miLista.EstaVacia()) {
                    cout << "La lista ha sido vaciada correctamente." << endl;
                }

                cout << "Respuestas a las preguntas: ..." << endl;
                system("pause");
                break;
            }
            case 2:
            {
                // Ejemplo operador [] con lista de enteros
                // Crear un objeto lista que almacene 10 datos de tipo int
                CLista<int> miLista;
                for (int i = 1; i <= 10; i++) {
                    miLista.Agregar(i);
                }

                // Sumar todos los números de la lista y provocar la excepción CIndiceIncorrecto
                int suma = 0;
                try {
                    for (int i = 0; i <= miLista.ObtenerUltimoIndice(); i++) {
                        suma += miLista[i];
                    }
                    cout << "La suma de los números es: " << suma << endl;

                    // Provocar excepción CIndiceIncorrecto
                    cout << miLista[10] << endl;
                }
                catch (CIndiceIncorrecto& e) {
                    cout << e.GetMensaje() << endl;
                }

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
                cout << " CONTRATO COPIA: " << copia << endl;
                system("pause");
                break;
            }
            case 4:
            {
                CContrato prueba(12345);
                // Agregar a "prueba" un siniestro urgente y otro normal
                prueba.AgregarSiniestro(CSiniestroUrgente(internacional, "Siniestro Urgente Ejemplo"));
                prueba.AgregarSiniestro(CSiniestroNormal("Siniestro Normal Ejemplo"));

                prueba.MostrarSiniestros();
                cout << endl;
                cout << "Respuestas a las preguntas: ..." << endl;
                system("pause");
                break;
            }
            case 5:
            {
                // Crear cliente
                CCliente cli("Juan");
                // Agregar un contrato con dos siniestros, urgente y normal, a cli
                CContrato contrato(1, "Contrato 1");
                contrato.AgregarSiniestro(CSiniestroUrgente(nacional, "Siniestro Urgente"));
                contrato.AgregarSiniestro(CSiniestroNormal("Siniestro Normal"));
                cli.AgregarContrato(contrato);

                // Mostrar datos
                cout << " Datos del cliente: \n" << endl << cli << endl;
                system("pause");

                cout << "Llamada explícita:\n" << const_cast<CCliente&>(cli).ObtenerNombre() << endl;
                system("pause");
                break;
            }
            case 6:
            {
                cout << "Respuestas a las preguntas: ..." << endl;
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
                system("pause");
                break;
            }
            case 8:
            {
                // Crear un cliente cli
                CCliente cli("Cliente 1");

                // Agregar a cli un contrato con siniestros
                CContrato contrato(1, "Contrato 1");
                contrato.AgregarSiniestro(CSiniestroUrgente(nacional, "Siniestro Urgente"));
                contrato.AgregarSiniestro(CSiniestroNormal("Siniestro Normal"));
                cli.AgregarContrato(contrato);

                // Mostrar cli
                cout << "Datos del cliente: \n" << endl;
                cli.MostrarContratos();

                system("pause");
                break;
            }
            case 9:
            {
                // Crear una matriz dinámica de tipo CCliente apuntada por "seguros"
                CCliente* seguros = new CCliente[MAX_CLIENTES];

                // Agregar contratos a los clientes de la matriz "seguros"
                for (int i = 0; i < MAX_CLIENTES; i++) {
                    CCliente cliente("Cliente " + to_string(i + 1));
                    for (int j = 1; j <= i + 1; j++) {
                        CContrato contrato(j, "Contrato " + to_string(j));
                        cliente.AgregarContrato(contrato);
                    }
                    seguros[i] = cliente;
                }

                // Contar el número total de contratos
                long total = 0;
                for (int i = 0; i < MAX_CLIENTES; i++)
                    total += seguros[i].ObtenerTotalContratos();
                cout << "\n El numero total de contratos de los clientes asciende a: ";
                cout << total << " contratos\n";
                system("pause");
                delete[] seguros;
                break;
            }
            case 10:
            {
                CSiniestroNormal s("Rotura de tambor");
                cout << endl;
                s.Mostrar();
                cout << endl;

                cout << "Respuesta a la pregunta: ..." << endl;
                system("pause");
                break;
            }
            case 11:
            {
                cout << "Respuesta a la pregunta: ..." << endl;
                system("pause");
                break;
            }
            case 12:
            {
                cout << "Respuesta a la pregunta: ..." << endl;
                system("pause");
                break;
            }
            case 13:
            {
                CContrato c(12345, "Cafetera C1Z", "2/1/2016", 100, 1000);
                CSiniestroUrgente s(nacional, "Fallo general");
                c.AgregarSiniestro(s);

                cout << "Respuestas a las preguntas: ..." << endl;
                system("pause");
                break;
            }
            case 14:
            {
                // Crear empresa1
                CEmpresa<CCliente> empresa1;
                // Agregar elementos a la empresa

                CCliente cliente1("Cliente 1");
                cliente1.AgregarContrato(CContrato(1, "Contrato 1"));
                empresa1.AgregarElemento(cliente1);

                CCliente cliente2("Cliente 2");
                cliente2.AgregarContrato(CContrato(1, "Contrato 1"));
                cliente2.AgregarContrato(CContrato(2, "Contrato 2"));
                empresa1.AgregarElemento(cliente2);

                // Crear empresa2 como copia de empresa1
                CEmpresa<CCliente> empresa2(empresa1);

                // Mostrar la empresa2
                cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;
                for (int i = 0; i < empresa2.ObtenerNumElementos(); i++) {
                    CCliente* cliente = empresa2.ObtenerElemento(i);
                    cout << "Cliente: " << cliente->ObtenerNombre() << endl;
                    cliente->MostrarContratos();
                }

                cout << "Respuestas a las preguntas: ..." << endl;
                system("pause");
                break;
            }
            case 15:
            {
                // Crear empresa1
                CEmpresa<CCliente> empresa1;
                // Agregar elementos a la empresa

                CCliente cliente1("Cliente 1");
                cliente1.AgregarContrato(CContrato(1, "Contrato 1"));
                empresa1.AgregarElemento(cliente1);

                CCliente cliente2("Cliente 2");
                cliente2.AgregarContrato(CContrato(1, "Contrato 1"));
                cliente2.AgregarContrato(CContrato(2, "Contrato 2"));
                empresa1.AgregarElemento(cliente2);

                // Guardar empresa1 en el archivo "empresa.bin"
                empresa1.Guardar("empresa.bin");

                cout << "La empresa ha sido guardada correctamente en el archivo 'empresa.bin'." << endl;
                system("pause");
                break;
            }
            case 16:
            {
                cout << "Fin del programa." << endl;
                break;
            }
            default:
                cout << "Opcion incorrecta." << endl;
                system("pause");
                break;
            }
        } while (opcion != numopciones);

        return 0;
    }
}

