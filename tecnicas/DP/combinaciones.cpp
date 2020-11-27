#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define INF 99999

int combinaciones(int n, int k)
{
  if (k > n)
    return 0;

  int **mat = new int *[n + 1];
  for (int i = 0; i <= n; i++)
  {
    mat[i] = new int[n + 1];
    // Innecesaria inicialización:
    // for (int j = 0; j <= n; j++)
    // {
    //   mat[i][j] = 0;
    // }
  }

  // inicializo bordes
  for (int i = 0; i <= n; i++)
  {
    mat[i][0] = 1;
    mat[i][i] = 1;
  }

  // cuerpo del DP
  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j < i; j++)
    {
      mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }

  return mat[n][k];
}

int main()
{
  int n, k;
  cout << "Ingrese el valor n:" << endl;
  cin >> n;
  cout << "Ingrese el valor k :" << endl;
  cin >> k;

  cout << "combinaciones(n,k) = " << combinaciones(n, k) << endl;

  return 0;
}