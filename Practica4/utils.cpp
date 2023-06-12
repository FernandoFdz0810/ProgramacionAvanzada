#include "utils.h"
#include <iostream>
#include <cstdlib>


using namespace utils;
using namespace std;

bool CUtils::LeerDato(int& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);

	try
	{
		cin >> dato;
		// Eliminar caracteres sobrantes. Por ejemplo '\n'
		cin.ignore(numeric_limits<int>::max(), '\n');
		// Deshabilitar excepciones
		cin.exceptions(ios::goodbit);
		return true;
	}

	catch (ios_base::failure& e)
	{
		if (cin.eof()) // Si el usuario introduzce (CTRL + Z) EOF
		{
			cin.clear();
			return false;
		}

		else // En caso de error se indica al usuario, se limpia el buffer de entrada, se ignoran caracteres como salto de linea, se solicita dato de nuevo.
		{
			cout << e.what() << ": dato no válido \n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			return LeerDato(dato);
		}
	}
}

bool CUtils::LeerDato(char* dato)
{
	cin.exceptions(ios::failbit || ios::badbit);

	try
	{
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin.exceptions(ios::goodbit);
		return true;
	}

	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			return false;
		}

		else
		{
			cout << e.what();
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			return LeerDato(dato);
		}
	}
}

float LeerFloat()
{
	int error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;

		// Escribir código que falta.

	} while (error);
	cin.ignore(numeric_limits<float>::max(), '\n'); //Eliminar \n
	return num;
}

int CUtils::CrearMenu(char* OpcionesMenu[], int numopciones)
{
	int i;
	int opcion = 0;

	cout << "\n\n________________________________\n\n";
	for (i = 1; i <= numopciones; i++)
		cout << " " << i << "." << OpcionesMenu[i-1] << endl;
	cout << "_______________________________\n";

	do
	{
		cout << "\nOpcion (1 - " << numopciones << "):";
		cout << ">> ";  CUtils::LeerDato(opcion);
	} while (opcion < 1 || opcion > numopciones);
	
	return opcion;
}

void LeerCadena(char* cadena, int n)
{
	int error;

	do
	{
		cin.getline(cadena, n, '\n'); //Obtenemos cadena, con el numero de elementos a leer hasta que haya salto de linea
		error = cin.rdstate() & ios::failbit; // Leemos entrada, en caso de que la cadena introducida sea mayor o igual que n se activa ios::failbit

		if (error)
		{
			cout << "El dato leido no es correcto";
			cin.clear(); // Limpiamos buffer de entrada
			cin.ignore(numeric_limits<int>::max(), '\n'); //Eliminar \n
		}
	} while (error);
	
}

char* CUtils::ConverMayus(char* str)
{
	for (int i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);

	return str;
}

string& ConverMayus(string& str)
{
	for (int i = 0; i < sizeof(str); i++)
		str[i] = toupper(str.at(i));
	
	return str;
}