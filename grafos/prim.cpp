#include <iostream>

using namespace std;

#define INF 99999

class Grafo
{
private:
  int **matAdy;
  int *vertices;
  int cant, tope;

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

  void prim()
  {
    // Inicializo vector de visitados en false
    bool *vis = new bool[tope];
    for (int i = 0; i < tope; vis[i++] = false)
      ;

    // Busco primer posición no vacía
    int origen = -1;
    while (vertices[++origen] == -1)
      ;

    // Visito al origen
    vis[origen] = true;

    // Repito k veces la búsqueda de la mejor combinación entre un visitado y un no visitado
    for (int k = 0; k < cant - 1; k++)
    {
      int posVis = -1, posNoVis = -1, min = INF;
      for (int i = 0; i < tope; i++)
      {
        if (vis[i])
        {
          for (int j = 0; j < tope; j++)
          {
            if (!vis[j] && matAdy[i][j] < min)
            {
              min = matAdy[i][j];
              posVis = i;
              posNoVis = j;
            }
          }
        }
      }

      if (min == INF)
        return;

      cout << posVis << " -> " << posNoVis << " = " << min << endl;

      vis[posNoVis] = true;
    }
  }
};