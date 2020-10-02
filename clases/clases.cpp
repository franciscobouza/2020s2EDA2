template <class T>
class NodoLista
{
private:
  T dato;
  NodoLista<T> *sig;

public:
  NodoLista(T dato) : dato(dato), sig(NULL) {}
  NodoLista(T dato, NodoLista<T> *sig) : dato(dato), sig(sig) {}
};

template <class T>
class Lista
{

public:
  Lista() : inicio(NULL) {}
  void insertarFin(T dato)
  {
    insertarFinRec(dato, inicio);
  }

private:
  NodoLista<T> *inicio;
  void insertarFinRec(T dato, NodoLista<T> *&nodo)
  {
    if (!nodo)
    {
      nodo = new NodoLista<T>(dato);
    }
    else
    {
      insertarFinRec(dato, nodo->sig);
    }
  }
};

int main()
{
  NodoLista<string> *nodoStr = new NodoLista<string>("Holi");
  NodoLista<int> *nodoStr = new NodoLista<int>(1891);
}