int **matAdy;
int *vertices;
int cant, tope;

int min(int a, int b)
{
  return a <= b ? a : b;
}

int **floyd()
{
  // Clono la matriz
  int **res = new int *[tope];
  for (int i = 0; i < tope; i++)
  {
    res[i] = new int[tope];
    for (int j = 0; j < tope; j++)
    {
      res[i][j] = matAdy[i][j];
    }
  }

  for (int k = 0; k < tope; k++)
  {
    for (int i = 0; i < tope; i++)
    {
      for (int j = 0; j < tope; j++)
      {
        res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
      }
    }
  }

  return res;
}