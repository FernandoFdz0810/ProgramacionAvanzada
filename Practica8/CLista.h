#if !defined (_LISTA_H)
#define _LISTA_H

#include "CNodoLista.h"


template <class T> 
class CLista
{
private:
  CNodoLista<T> * m_Primero;
  CNodoLista<T> * m_Actual;
  CNodoLista<T> * m_Ultimo;

public:
  CLista();
  CLista(const T& Obj);
  CLista(const CLista<T>& Lista);
  ~CLista();

  CLista<T>& operator=(const CLista<T>& Lista);
  bool EstaVacia() const { return m_Primero == NULL; }
  bool TieneMas() const { return m_Actual != NULL; }
  void AgregarObjeto(const T& Obj);
  void Vaciar();
  void Restart() const;
  T& GetPrimero() const;
  T& GetActual() const;
  T& operator[](int indice);


};

#endif
