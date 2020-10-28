#define INF 99999

void dijkstraConCola(Grafo g, int unVOrigen)
{
  int *distancia = new int[g->tope];
  int *anterior = new int[g->tope];
  Cola<int> *cola = new Cola<int>();
  for (int i = 0; i < g->tope; i++)
  {
    distancia[i] = INF;
    anterior[i] = -1;
  }
  distancia[unVOrigen] = 0;
  cola->encolar(unVOrigen);
  while (!cola->esVacia())
  {
    int minPos = cola->desencolar();
    int min = distancia[minPos];
    for (int j = 0; j < g->tope; j++)
    {
      if (g->matrizAdyacencia[minPos][j] != INF)
      {
        int suma = g->matrizAdyacencia[minPos][j] + min;
        if (suma < distancia[j])
        {
          anterior[j] = minPos;
          distancia[j] = suma;
          if (!cola->pertenece(j))
            cola->encolar(j);
        }
      }
    }
  }
}
