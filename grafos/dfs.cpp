#include <iostream>

using namespace std;

#define INF 99999

NodoAdy **listaAdy;
int *vertices;
int cant, tope;

// void mostrarRec(NodoAB *nodo)
// {
//   if (nodo)
//   {
//     cout << nodo->dato << endl;
//     mostrarRec(nodo->izq);
//     mostrarRec(nodo->der);
//   }
// }

struct NodoAdy
{
  int pos;
  int costo;
  NodoAdy *sig;
};

void DFSInterno(int pos, int largo, bool *vis)
{
  cout << vertices[pos];
  vis[pos] = true;
  NodoAdy *nodoListaAdy = listaAdy[pos];
  while (nodoListaAdy)
  {
    if (!vis[nodoListaAdy->pos])
      DFSInterno(nodoListaAdy->pos, largo, vis);
    nodoListaAdy = nodoListaAdy->sig;
  }
}

void DFS(int pos, int largo)
{
  bool *vis = new bool[largo];
  for (int i = 0; i < largo; vis[i++] = false)
    ;
  DFSInterno(pos, largo, vis);
}