#include <fs>

template <class T>
class CEmpresa
{
private:
    T* m_pElem;
    int m_nElem;

public:
    CEmpresa() : m_nElem(0), m_pElem(nullptr) {}
    CEmpresa(const CEmpresa& a);
    CEmpresa& operator=(const CEmpresa& a);
    ~CEmpresa();

    void AgregarElemento(const T& elem);
    int Tamanyo() const { return m_nElem; }
    T& GetElemento(int nElem) const;
    T& operator[](int nElem) const;
};


