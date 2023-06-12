#include "MemoryManager.h"
#include "CMonomio.h"
//#include "CTermino.h"
#include "CPolinomio.h"

using namespace std;

int main()
{
	{
		CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N;
		CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4);

		P << m1 << m2 << -m4 << m3;
		Q << m4 << m1 << m2 << -m3;
		R << m3 << m4 << -m2;
		S << m2 << m3 << m4 << -m2;
		T << -m2 << -m3 << -m4 << m3;
		U << m2 << m3 << m4 << -m4;
		V << m2 << m3 << m4 << -m2 << -m3 << -m4;
		W << m2 << m3 << -m2 << -m3;
		X << m2 << -m2;
		Y << m2 << m3 << m4 << m2;
		Z << -m2 << -m3 << -m4 << -m3;
		N << m2 << m3 << m4 << m4;
		cout << "P = " << P << endl
			 << "Q = " << Q << endl
			 << "R = " << R << endl
			 << "S = " << S << endl
			 << "T = " << T << endl
			 << "U = " << U << endl
			 << "V = " << V << endl
			 << "W = " << W << endl
			 << "X = " << X << endl
			 << "Y = " << Y << endl
			 << "Z = " << Z << endl
			 << "N = " << N << endl;

		system("pause");

		CPolinomio Suma, Resta, Producto;
		CMonomio m5(3, 2), m6(-2, 1);

		cout << endl;
		cout << " CPolinomio A = P (constructor copia)" << endl;
		CPolinomio A(P);
		cout << " A = " << A << endl;
		system("pause");

		cout << endl;
		cout << " B = Q (operador de asignacion)" << endl;
		CPolinomio B;
		B << Q;
		cout << " B = " << B << endl;
		system("pause");

		cout << endl;
		cout << " P = P (evitar autoasignacion)" << endl;
		P = P;
		cout << " P = " << P << endl;
		system("pause");

		cout << endl;
		cout << " Probando el constructor con un coef. y un exp." << endl;
		CPolinomio C(2.5);
		CPolinomio D(2.5, 5);
		cout << " C = " << C << endl;
		cout << " D = " << D << endl;
		system("pause");

		cout << endl;
		cout << " Probando el constructor con un monomio" << endl;
		CPolinomio E(m4);
		cout << " E = " << E << endl;
		system("pause");

		cout << endl;
		cout << " Obteniendo el grado del polinomio" << endl;
		cout << " El grado de U es: " << U.Grado() << endl;
		system("pause");

		cout << endl;
		cout << " Probando el constructor con vector<CMonomio>" << endl;
		vector<CMonomio> vec;
		vec = vector<CMonomio>(3);
		vec[0] = m2;
		vec[1] = m3;
		vec[2] = m4;
		CPolinomio F(vec);
		cout << " F = " << F << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador >" << endl;
		cout << " P = " << P << endl;
		cout << " U = " << U << endl;
		if (P > U)
		{
			cout << " P es de mayor grado que U" << endl;
		}
		system("pause");

		cout << endl;
		cout << " Probando el operador ==" << endl;
		cout << " P = " << P << endl;
		cout << " Q = " << Q << endl;
		if (Q == P)
		{
			cout << " P es de igual grado que Q" << endl;
		}
		system("pause");

		cout << endl;
		cout << " Probando el operador - unario" << endl;
		cout << " Q = " << Q << endl;
		cout << " -Q = " << -Q << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador +" << endl;
		cout << " N = " << N << endl;
		cout << " U = " << U << endl;
		Suma = N + U;
		cout << " N + U : " << Suma << endl;
		system("pause");

		cout << endl;
		cout << " Probando los operadores - y +=" << endl;
		cout << " R = " << R << endl;
		cout << " S = " << S << endl;
		Resta = R - S;
		cout << " R - S : " << Resta << endl;
		R += S;
		cout << " R += S :" << R << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador -=" << endl;
		cout << " N = " << N << endl;
		cout << " Y = " << Y << endl;
		N -= Y;
		cout << " N -= Y : " << N << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador  []" << endl;
		cout << " Polinomio P:" << P << endl;
		cout << " Coeficiente de P[4]: " << P[4] << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador  ()" << endl;
		CPolinomio G;
		G << m5 << m6;
		cout << " Polinomio G:" << G;
		cout << ", G(0.5) = " << G(0.5) << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador *" << endl;
		cout << " Q = " << Q << endl;
		cout << " S = " << S << endl;
		Producto = Q * S;
		cout << " Q * S : " << Producto << endl;
		system("pause");

		cout << endl;
		cout << " Probando el operador *=" << endl;
		cout << " P = " << P << endl;
		cout << " Q = " << Q << endl;
		P *= Q;
		cout << " P *= Q : " << P << endl;
		system("pause");

	}

	cout << endl;
	MemoryManager::dumpMemoryLeaks();
	system("pause");
}