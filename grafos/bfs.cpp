#include <iostream>

using namespace std;

#define INF 99999

NodoAdy **listaAdy;
int *vertices;
int cant, tope;

struct NodoAdy
{
  int pos;
  int costo;
  NodoAdy *sig;
};

void BFS(int pos, int largo)
{
  Cola<int> *cola = new ColaImp<int>();
  bool *vis = new bool[largo];
  for (int i = 0; i < largo; vis[i++] = false)
    ;
  cola->encolar(pos);
  vis[pos] = true;
  while (!cola->esVacia())
  {
    int elem = cola->desencolar();
    cout << vertices[elem] << endl;
    NodoAdy *nodoListaAdy = listaAdy[elem];
    while (nodoListaAdy)
    {
      if (!vis[nodoListaAdy->pos])
      {
        cola->encolar(nodoListaAdy->pos);
        vis[nodoListaAdy->pos] = true;
      }
      nodoListaAdy = nodoListaAdy->sig;
    }
  }
}