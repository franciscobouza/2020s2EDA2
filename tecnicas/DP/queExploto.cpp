#define INF 99999

int max(int a, int b)
{
  return a >= b ? a : b;
}

int queExploto(int pisos, int garrafas)
{
  int **tiradas = new int *[garrafas];
  for (int i = 0; i < garrafas; tiradas[i++] = new int[pisos + 1])
    ;

  // Inicializo matriz
  for (int i = 0; i < garrafas; i++)
  {
    tiradas[i][0] = 0;
    tiradas[i][1] = 1;
  }
  for (int j = 2; j < pisos + 1; j++)
  {
    tiradas[0][j] = j;
  }

  int res;

  // Comienzo DP
  for (int i = 1; i < garrafas; i++)
  {
    for (int j = 2; j < pisos + 1; j++)
    {
      tiradas[i][j] = INF;
      for (int x = 1; x <= j; x++)
      {
        res = 1 + max(tiradas[i - 1][x - 1], tiradas[i][j - x]);
        if (res < tiradas[i][j])
          tiradas[i][j] = res;
      }
    }
  }
  return tiradas[garrafas - 1][pisos];
}

int main()
{

  return 0;
}