#include <iostream>

using namespace std;

class Elemento
{
public:
  int peso;
  int valor;
  Elemento(int peso, int valor) : peso(peso), valor(valor) {}
};

int *calcularMonedas(int *monedas, int cantMonedas, int &valorARepartir)
{
  int *ret = new int[cantMonedas];
  for (int i = 0; i < cantMonedas; ret[i++] = 0)
    ;

  for (int i = 0; i < cantMonedas && valorARepartir > monedas[cantMonedas - 1]; i++)
  {
    while (monedas[i] <= valorARepartir)
    {
      valorARepartir -= monedas[i];
      ret[i]++;
    }
  }
  return ret;
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

  int *monedasAEntregar = calcularMonedas(monedas, cantMonedas, valorARepartir);
  int cantMonedasEntregadas = 0;
  for (int i = 0; i < cantMonedas; i++)
  {
    if (monedasAEntregar[i] > 0)
    {
      cout << "Dar " << monedasAEntregar[i] << " monedas de valor " << monedas[i] << endl;
      cantMonedasEntregadas += monedasAEntregar[i];
    }
  }
  cout << (cantMonedasEntregadas == 1 ? "Se entrego " : "Se entregaron ") << cantMonedasEntregadas << (cantMonedasEntregadas == 1 ? " moneda" : " monedas") << endl;
  if (valorARepartir > 0)
  {
    cout << "Sobro " << valorARepartir << endl;
  }

  // cout << "[";
  // for (int i = 0; i < cantMonedas - 1; i++)
  // {
  //   cout << monedas[i] << ", ";
  // }
  // if (cantMonedas > 0)
  //   cout << monedas[cantMonedas - 1];
  // cout << "]" << endl;

  return 0;
}