#if !defined (C_UTILS_H_)
#define _CUTILS_H_


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<limits>
#include<string>
#include"MemoryManager.h"

#pragma once

using namespace std;

namespace utils
{
	class CUtils
	{
	public:
		static bool LeerDato(int& dato);
		static bool LeerDato(float& dato);
		static bool LeerDato(char* dato);
		static int  CrearMenu(char* opciones_menu[], int num_opciones);
		static bool LeerDato(char* c, int n);
		static char* ConverMayus(char* str);
	};
	
}
#endif

