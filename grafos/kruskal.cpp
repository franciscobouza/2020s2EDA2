#include <iostream>

using namespace std;

#define INF 99999

class Arista
{
public:
  int posOrigen;
  int posDestino;
  int costo;

  Arista(int posOrigen, int posDestino, int costo) : posOrigen(posOrigen), posDestino(posDestino), costo(costo);
};

class NodoLista
{
public:
  NodoLista *sig;
  int pos;

  NodoLista(int pos) : sig(NULL), pos(pos) {}
  NodoLista(NodoLista *sig, int pos) : sig(sig), pos(pos) {}
};

class Grafo
{
private:
  int **matAdy;
  int *vertices;
  int cant, tope;

  void concatenar(NodoLista *&origen, NodoLista *&destino)
  {
    if (origen)
    {
      concatenar(origen->sig, destino);
    }
    else
    {
      origen = destino;
    }
  }

public:
  Grafo(int tope)
  {
    this->tope = tope;
    this->cant = 0;
    vertices = new int[tope];
    for (int i = 0; i < tope; vertices[i++] = -1)
      ;
    matAdy = new int *[tope];
    for (int i = 0; i < tope; i++)
    {
      matAdy[i] = new int[tope];
      for (int j = 0; j < tope; j++)
      {
        matAdy[i][j] = INF;
      }
    }
  }

  // V^2 Log(E)

  void kruskal()
  {
    // V
    NodoLista **componentesConexas = new NodoLista *[tope];
    for (int i = 0; i < tope; i++)
    {
      componentesConexas[i] = new NodoLista(i);
    }

    // V^2 Log(E)
    Heap<Arista *> *cp = new Heap<Arista *>(tope);
    for (int i = 0; i < tope; i++)
    {
      for (int j = 0; j < tope; j++)
      {
        if (matAdy[i][j] != 0)
        {
          Arista *a = new Arista(i, j, matAdy[i][j]);
          cp->insertar(a);
        }
      }
    }

    int cantAristasAgregadas = 0;

    // E * Log(E)

    while (!cp->esVacia() && cantAristasAgregadas < tope - 1)
    {

      Arista *arista = cp->borrarMin();
      int posO, posD;
      // hallo la posición del origen y el destino de mi arista, para chequear si están en la misma componente conexa
      for (int i = 0; i < tope; i++)
      {
        NodoLista *comp = componentesConexas[i];
        while (comp)
        {
          if (comp->pos == arista->posOrigen)
          {
            posO = i;
          }
          if (comp->pos == arista->posDestino)
          {
            posD = i;
          }
          comp = comp->sig;
        }
      }
      if (posO == posD)
        continue;
      cout << vertices[arista->posOrigen] << " -> " << vertices[arista->posDestino] << " = " << arista->costo << endl;
      cantAristasAgregadas++;
      concatenar(componentesConexas[posO], componentesConexas[posD]);
      componentesConexas[posD] = NULL;
    }
  }
};