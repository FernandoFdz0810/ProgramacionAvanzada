#if !defined (C_REGISTRO_H_)
#define _CREGISTRO_H_	

#include"empleado.h"

using namespace std;

class CRegistroDiario {

private:
	int nElementosMax;
	CFicha** personas;

public:
	CRegistroDiario(int nElementosMax); //Constructor
	~CRegistroDiario(); //Destructor
	CRegistroDiario(const CRegistroDiario& registro);	//Constructor copia
	CRegistroDiario& operator=(const CRegistroDiario& registro);	//operador de asignación
	void Destruir();

	bool AgregarPersona(CFicha* ficha); // Metodo AgregarPersona recibe como parametro un puntero a la calse base CFicha (REVISAR!) //Es de tipo bool...
	void VisualizarRegistro(); // LLama al metodo Visualizar para cada uno de los empleados o clientes de clase CRegistroDiario
	
	static inline bool EsEmpleado(const CFicha& obj);// Devuelve True si persona pasada como argumento es un empleado

	
	void VisualizarEmpleados();
	CFicha* operator[](int i) const; // operador indexación

	bool RegistroLLeno(); //check nElementos
	int GetNumElementosMax() const { return nElementosMax; } //devuelve nElementosMax

	const  CFicha& EncontrarPorNombre(const string& nombre) const;
};



#endif