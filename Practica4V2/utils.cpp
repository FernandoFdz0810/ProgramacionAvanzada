#include"utils.h"

using namespace utils;		//se introduce en namespace

bool CUtils::LeerDato(int& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);

	try
	{
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
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
			cout << e.what() << "\n El dato introducido no es correcto, vuelva a introducirlo: ";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
			return LeerDato(dato);
		}
	}
}

bool CUtils::LeerDato(float& dato)	//Igual
{
	cin.exceptions(ios::failbit | ios::badbit);

	try
	{
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
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
			cout << e.what() << "\n El dato introducido no es correcto, vuelva a introducirlo: ";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); //eliminar 'n
			return LeerDato(dato);
		}
	}
}

int CUtils::CrearMenu(string opciones_menu[], int num_opciones)
{
    int opcion=0;
    system("cls"); // limpiar la pantalla
    // Presentar el menú
    printf("\n Menu:\n\n");
    for (int i = 0; i < num_opciones; i++)
		cout << "\t" << i + 1 << ". " << opciones_menu[i] << endl;
	do
	{
		cout << ">> "; //opcion = LeerDato(opcion);
	//	if (opcion < 1 || opcion > num_opciones)	//Check
	//	{
	//		cout << " ERROR: Esta opcion no existe. \n" << endl;
	//		system("pause");
	//		return 0;
	//	}
	} while ((opcion < 1 || opcion > num_opciones) && LeerDato(opcion) == false);
		//} while (opcion < 1 || opcion > num_opciones);
	return opcion;
}

bool CUtils::LeerDato(string& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);

	try
	{	
		getline(cin, dato);
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
			cout << e.what() << "\n El dato introducido no es correcto, vuelva a introducirlo: ";
			cin.clear();
			return LeerDato(dato);
		}
	}
}

string& CUtils::ConverMayus(string& str)
{
	int unsigned i;

	for (i = 0; i < str.size(); i++)
		str[i] = toupper(str.at(i));

	return str;
}