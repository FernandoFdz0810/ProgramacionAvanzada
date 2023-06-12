#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<limits>
#include<string>
#include"MemoryManager.h"

using namespace std;

int LeerInt();
float LeerFloat();
int CrearMenu(string opciones_menu[], int num_opciones);
void LeerCadena(string& c, int n);
//char* ConverMayus(char* str);
string& ConverMayus(string& str);