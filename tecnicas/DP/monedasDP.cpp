#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define INF 99999

int min(int a, int b)
{
  return a <= b ? a : b;
}

int monedasDP(int *monedas, int cantMonedas, int cambio, int *cantMonedasUsadas)
{
  int **mat = new int *[cantMonedas];
  for (int i = 0; i < cantMonedas; i++)
  {
    mat[i] = new int[cambio + 1];
  }

  for (int i = 0; i < cantMonedas; mat[i++][0] = 0)
    ;

  for (int j = 1; j <= cambio; j++)
  {
    mat[0][j] = j < monedas[0] ? INF : min(1 + mat[0][j - monedas[0]], INF);
  }

  for (int i = 1; i < cantMonedas; i++)
  {
    for (int j = 1; j <= cambio; j++)
    {
      if (j < monedas[i])
      {
        mat[i][j] = mat[i - 1][j];
      }
      else
      {
        mat[i][j] = min(mat[i - 1][j], 1 + mat[i][j - monedas[i]]);
      }
    }
  }

  cout << endl;
  for (int i = 0; i < cantMonedas; i++)
  {
    for (int j = 0; j <= cambio; j++)
    {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;

  int posJ = cambio, posI = cantMonedas - 1;
  while (posI != 0 && posJ != 0)
  {
    if (mat[posI][posJ] == mat[posI - 1][posJ])
    {
      posI--;
    }
    else
    {
      cantMonedasUsadas[posI]++;
      posJ -= monedas[posI];
    }
  }
  while (posJ != 0)
  {
    cantMonedasUsadas[0]++;
    posJ -= monedas[0];
  }

  return mat[cantMonedas - 1][cambio];
}

int main()
{
  int cantMonedas, moneda, valorARepartir;
  cout << "Ingrese la cantidad de monedas" << endl;
  cin >> cantMonedas;
  int *monedas = new int[cantMonedas];
  for (int i = 0; i < cantMonedas; i++)
  {
    cout << "Ingrese la moneda " << (i + 1) << ":" << endl;
    cin >> moneda;
    monedas[i] = moneda;
  }

  cout << "Ingrese el valor a repartir:" << endl;
  cin >> valorARepartir;

  int *cantMonedasUsadas = new int[cantMonedas];
  for (int i = 0; i < cantMonedas; cantMonedasUsadas[i++] = 0)
    ;

  cout << "La cantidad minima de monedas es: " << monedasDP(monedas, cantMonedas, valorARepartir, cantMonedasUsadas) << endl;
  for (int i = 0; i < cantMonedas; i++)
  {
    if (cantMonedasUsadas[i] != 0)
    {
      cout << "Cant. monedas de " << monedas[i] << " usadas: " << cantMonedasUsadas[i] << endl;
    }
  }
  return 0;
}