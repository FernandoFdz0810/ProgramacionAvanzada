#include "utils.h"
#include <iostream>

using namespace std;

int LeerInt()
{
	int  error;
	int num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;

		// Si existe un error se debe limpiar el buffer 

		if (error)
		{
			cout << "\nEl dato que has introducido no es correcto, por favor, vuelva a intentarlo.\n";
			cin.clear(); // Limpiamos buffer
			cin.ignore(numeric_limits<int>::max(), '\n'); // Eliminamos caracteres residuales 
		}

	} while (error);
	cin.ignore(numeric_limits<int>::max(), '\n'); //Eliminar \n
	return num;
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

int CrearMenu(char* OpcionesMenu[], int numopciones)
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
		opcion = LeerInt();
	} while (opcion < 1 || opcion > numopciones);
	
	return opcion;
}