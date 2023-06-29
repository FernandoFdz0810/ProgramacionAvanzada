#if !defined (C_UTILS_H_)
#define _CUTILS_H_

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<limits>
#include<string>
#include"MemoryManager.h"

using namespace std;

namespace utils
{
	class CUtils
	{

	public:
		static bool LeerDato(int& dato); //bool LeerDato(int& dato)
		static bool LeerDato(float& dato); //bool LeerDato(float& dato)
		static int CrearMenu(const char* opciones_menu[], int num_opciones);
		//void LeerCadena(char* c, int n); //bool LeerDato(string& dato)
		static bool LeerDato(string& dato); //bool LeerDato(char* dato, int n) 
		static string& ConverMayus(string& str);
	};
};
#endif 
