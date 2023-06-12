#pragma once

struct MatFloat
{
	int nFilas; // Número de filas
	int nColumnas; // Número de Columnas
	float** ppMatrizF; // Datos de la matriz
};

float** ConstruirMatriz(int, int);
void IntroducirDatos(MatFloat*);
void Mostrar(MatFloat);
void Destruir(MatFloat*);


