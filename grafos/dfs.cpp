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

bool DFSInterno(int pos, int largo, bool *vis)
{
  cout << vertices[pos];
  NodoAdy *nodoListaAdy = listaAdy[pos];
  while (nodoListaAdy)
  {
    if (!vis[nodoListaAdy->pos])
    {
      vis[nodoListaAdy->pos] = true;
      bool ret = DFSInterno(nodoListaAdy->pos, largo, vis);
      if (ret)
        return true;
      vis[nodoListaAdy->pos] = false;
    }
    else
    {
      return true;
    }
    nodoListaAdy = nodoListaAdy->sig;
  }
  return false;
}

void DFS(int pos, int largo)
{
  bool *vis = new bool[largo];
  for (int i = 0; i < largo; vis[i++] = false)
    ;
  vis[pos] = true;
  DFSInterno(pos, largo, vis);
}