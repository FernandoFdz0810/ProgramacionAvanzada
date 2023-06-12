#include"utils.h"

int LeerInt()
{
	int error, num;

	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;

		if (error)	//Check
		{
			cout << "\n ERROR: El dato introducido no es correcto, vuelva a introducirlo...\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
		}
	} while (error);

	cin.ignore(numeric_limits<int>::max(), '\n');// eliminar '\n'

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

		if (error)	//Check
		{
			cout << "\n ERROR: El dato introducido no es correcto, vuelva a introducirlo...\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
		}
	} while (error);

	cin.ignore(numeric_limits<int>::max(), '\n');// eliminar '\n'
	return num;
}

int CrearMenu(char* opciones_menu[], int num_opciones)
{
	int opcion;
	system("cls"); // limpiar la pantalla
	// Presentar el menú
	printf("\n Menu:\n\n");
	for (int i = 0; i < num_opciones; i++)
		printf("\t%d. %s\n", i + 1, opciones_menu[i]);
	// Elegir una opción y verificar que es correcta
	do
	{
		cout << ">> "; opcion = LeerInt();
		if (opcion < 1 || opcion > num_opciones)	//Check
		{
			cout << " ERROR: Esta opcion no existe. \n" << endl;
			system("pause");
			return 0;
		}
	} while (opcion < 1 || opcion > num_opciones);
	return opcion;
}

void LeerCadena(char* c, int n)
{
	int error;

	do
	{
		cin.getline(c, n, '\n');
		error = cin.rdstate() & ios::goodbit;

		if (error)
		{
			cout << "\n El dato leido no es correcto, vuelva a introducirlo: ";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
		}
	} while (error);
}
char* ConverMayus(char* str)
{
	int i;

	for (i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);

	return str;
}