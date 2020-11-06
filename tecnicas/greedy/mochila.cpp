// By Santiago Bolumburu (+1)

#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define INF 99999
class Elemento
{
public:
  int peso;
  int valor;
  int cantidad;
  Elemento(int peso, int valor) : peso(peso), valor(valor), cantidad(0) {}
};
Elemento **mochilaAvida(Elemento **vec, int cantElemMoch, int &topeMoch, int &valTotal)
{
  Elemento **ret = new Elemento *[cantElemMoch];
  for (int i = 0; i < cantElemMoch; i++)
  {
    ret[i] = new Elemento(vec[i]->peso, vec[i]->valor);
    while (topeMoch >= ret[i]->peso)
    {
      ret[i]->cantidad++;
      topeMoch -= ret[i]->peso;
      valTotal += ret[i]->valor;
    }
  }
  return ret;
}
int main()
{
  int cantElementos;
  cout << "Cantidad de elementos:" << endl;
  cin >> cantElementos;
  cout << endl;
  Elemento **vecElem = new Elemento *[cantElementos];
  for (int i = 0; i < cantElementos; i++)
  {
    cout << "Datos elemento " << i << ":" << endl;
    int peso;
    cout << "Peso: " << endl;
    cin >> peso;
    int valor;
    cout << "Valor: " << endl;
    cin >> valor;
    vecElem[i] = new Elemento(peso, valor);
  }
  int topeMochila;
  cout << "Tope mochila:" << endl;
  cin >> topeMochila;
  cout << endl;
  int valTotal = 0;
  Elemento **respuesta = mochilaAvida(vecElem, cantElementos, topeMochila, valTotal);
  for (int i = 0; i < cantElementos; i++)
  {
    if (respuesta[i]->cantidad > 0)
    {
      cout << "Cantidad del elemento " << i << " (Peso: " << respuesta[i]->peso << ", valor: "
           << respuesta[i]->valor << "): " << respuesta[i]->cantidad << endl;
    }
  }
  cout << "Valor total: " << valTotal << endl;
}