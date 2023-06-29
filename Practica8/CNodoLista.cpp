#include "CNodoLista.h"

template<class T>
CNodoLista<T>::CNodoLista(const T& Obj, CNodoLista<T> *pNodo)
: m_Dato(Obj)
{
	this ->m_pSigNodo = pNodo;
}

template<class T>
CNodoLista<T>::CNodoLista(const CNodoLista<T> &NodoLista)
{
	this->m_Dato = T{ NodoLista.m_Dato };
	~CNodoLista();
}

template<class T>
CNodoLista<T>& CNodoLista<T>::operator=(const CNodoLista<T>& NodoLista)
{
	this->m_Dato = T{ NodoLista.m_Dato };
	~CNodoLista();
	return *this;
}

