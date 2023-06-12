#pragma once

struct MatFloat
{
	int nFilas; // N�mero de filas
	int nColumnas; // N�mero de Columnas
	float** ppMatrizF; // Datos de la matriz
};

float** ConstruirMatriz(int, int);
void IntroducirDatos(MatFloat*);
void Mostrar(MatFloat);
void Destruir(MatFloat*);


