#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define INF 99999

int combinaciones(int n, int k)
{
  if (k > n)
    return 0;

  int *vec = new int[n + 1];

  // inicializo bordes
  vec[0] = 1;

  // cuerpo del DP
  for (int i = 1; i <= n; i++)
  {
    vec[i] = 1;
    for (int j = i - 1; j > 0; j--)
    {
      vec[j] = vec[j] + vec[j - 1];
    }
  }

  return vec[k];
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