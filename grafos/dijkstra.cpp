int **matAdy;
int *vertices;
int cant, tope;

#define INF 99999

// Asumo que los vectores fueron previamente declarados y creados con largo "tope"
void dijkstra(int origen, int *&dist, int *&ant, bool *&vis)
{
  // Inicializo a los tres vectores
  for (int i = 0; i < tope; dist[i] = INF, ant[i] = -1, vis[i] = false, i++)
    ;
  // Seteo al origen como con distancia 0
  dist[origen] = 0;
  // Comienzo proceso repetitivo
  for (int k = 0; k < cant; k++)
  {
    // Hallo elemento no visitado de menor distancia desde el origen
    int posMin = -1, min = INF;
    for (int i = 0; i < tope; i++)
    {
      if (!vis[i] && dist[i] < min)
      {
        posMin = i;
        min = dist[i];
      }
    }
    // Si no encuentro candidato, me voy
    if (posMin == -1)
      return;
    // Visito al vértice
    vis[posMin] = true;
    for (int j = 0; j < tope; j++)
    {
      if (!vis[j])
      {
        int suma = dist[posMin] + matAdy[posMin][j];
        if (matAdy[posMin][j] != INF && suma < dist[j])
        {
          dist[j] = suma;
          ant[j] = posMin;
        }
      }
    }
  }
}