int **matAdy;
int *vertices;
int cant, tope;

#define INF 99999

int min(int a, int b)
{
  return a <= b ? a : b;
}

bool **warshall()
{
  // Clono la matriz
  bool **res = new bool *[tope];
  for (int i = 0; i < tope; i++)
  {
    res[i] = new bool[tope];
    for (int j = 0; j < tope; j++)
    {
      res[i][j] = matAdy[i][j] != INF;
    }
  }

  for (int k = 0; k < tope; k++)
  {
    for (int i = 0; i < tope; i++)
    {
      for (int j = 0; j < tope; j++)
      {
        res[i][j] = res[i][j] || res[i][k] && res[k][j];
      }
    }
  }

  return res;
}