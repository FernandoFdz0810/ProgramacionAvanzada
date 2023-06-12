#include"registro.h"

CRegistroDiario::CRegistroDiario(int nElementos)
{
	const char* error = "El número de elementos es <= 0";

	if (nElementos <= 0)
	{
		cout << "Ocurrio una excepción\n";
		throw &error;
	}
	else
	{

		personas = new (nothrow) CFicha * [nElementos];
		for (int i = 0; i < nElementos; i++)
		{
			personas[i] = NULL;
		}
		nElementosMax = nElementos; //hay que asignar el numero de elementos de la matriz
	}
}


void CRegistroDiario::Destruir()
{	
	for (int j = 0; j < GetNumElementosMax(); j++)
	{
		delete personas[j];
	}

	delete[] personas;	// delete clase personas
	personas = NULL;
}


CRegistroDiario::CRegistroDiario(const CRegistroDiario& registro)
{
	*this = registro;
}


CRegistroDiario& CRegistroDiario:: operator=(const CRegistroDiario& registro)
{
	if (this == &registro)
		return *this;

	if (this->personas != NULL)
		this->~CRegistroDiario();

	this->personas = new (nothrow) CFicha * [registro.nElementosMax];

	for (int i = 0; i < registro.GetNumElementosMax(); i++)
	{
		if (registro[i] != NULL)
			personas[i] = registro[i]->Clonar();
		else
			this->personas[i] = NULL;
	}

	nElementosMax = registro.GetNumElementosMax();
}



bool CRegistroDiario::AgregarPersona(CFicha* ficha)
{
	if (RegistroLLeno() == false)
	{
		for (int i = 0; i < GetNumElementosMax(); i++)
		{
			if (this->personas[i] == NULL)
			{
				this->personas[i] = ficha->Clonar();
				return true;
			}
		}
	}
	else
	{
		cout << "\n No se permite agregar mas personas." << endl;
		return false;
	}
}


void CRegistroDiario::VisualizarRegistro()
{
	for (int i = 0; i < GetNumElementosMax(); i++)
	{	
		if (personas[i] == NULL)
			break;

		personas[i]->Visualizar();

		system("pause");
	}
}

void CRegistroDiario::VisualizarEmpleados()
{
	for (int i = 0; i < GetNumElementosMax(); i++)
	{
		if (personas[i] == NULL)
			break;

		if (EsEmpleado(*this->personas[i]))
			personas[i]->Visualizar();

		system("pause");
	}
}

//Metodo Destructor
CRegistroDiario::~CRegistroDiario()
{	
	Destruir();
	cout << "\nDestructor invocado\n";
}


CFicha* CRegistroDiario:: operator[](int i) const
{
	if (i > 0 || i < GetNumElementosMax())
	{
		return this->personas[i];
	}
	else
	{
		cout << "\n ERROR" << endl;
		return NULL;
	}
}


bool CRegistroDiario::RegistroLLeno()
{
	if (this->personas[GetNumElementosMax() - 1] != NULL)
		return true;

	return false;
}

const CFicha& CRegistroDiario::EncontrarPorNombre(const string& nombre) const 
{
	CFicha* p = nullptr;

	for (int i = 0; i < GetNumElementosMax(); i++) 
	{
		if (this->personas[i]->ObtenerNombre() == nombre) 
		{
			p = this->personas[i];
			p->Visualizar();
			system("pause");
		}
	}

	if (p == nullptr) {
		cout << "\n ERROR" << endl;
		system("pause");
	}

	return *p;
}

bool CRegistroDiario::EsEmpleado(const CFicha& obj) { // Devuelve True si persona pasada como argumento es un empleado
	bool ret = true;
	try {
		auto dummy = dynamic_cast<const CEmpleado&>(obj);
	}
	catch (const bad_cast& e) {
		ret = false;
	}
	return ret;
};