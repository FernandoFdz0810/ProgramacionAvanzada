#include "CEmpresa.h"

template<class T>
CEmpresa<T>::CEmpresa(const CEmpresa<T> &a) {
	*this = a;
}

template <class T>
CEmpresa<T>::CEmpresa(const CEmpresa& a)
{
    m_nElem = a.m_nElem;
    m_pElem = new T[m_nElem];
    for (int i = 0; i < m_nElem; i++)
    {
        m_pElem[i] = a.m_pElem[i];
    }
}

template <class T>
CEmpresa<T>& CEmpresa<T>::operator=(const CEmpresa& a)
{
    if (this == &a)
        return *this;

    delete[] m_pElem;

    m_nElem = a.m_nElem;
    m_pElem = new T[m_nElem];
    for (int i = 0; i < m_nElem; i++)
    {
        m_pElem[i] = a.m_pElem[i];
    }

    return *this;
}

template <class T>
CEmpresa<T>::~CEmpresa()
{
    delete[] m_pElem;
}

template <class T>
void CEmpresa<T>::AgregarElemento(const T& elem)
{
    T* newArray = new T[m_nElem + 1];
    for (int i = 0; i < m_nElem; i++)
    {
        newArray[i] = m_pElem[i];
    }
    newArray[m_nElem] = elem;

    delete[] m_pElem;
    m_pElem = newArray;
    m_nElem++;
}

template <class T>
T& CEmpresa<T>::GetElemento(int nElem) const
{   
    if(nElem < 0 || nElem >= m_nElem)
		throw std::out_of_range("Indice fuera de rango")
    return m_pElem[nElem];
}

template <class T>
T& CEmpresa<T>::operator[](int nElem) const
{
    return m_pElem[nElem];
}

