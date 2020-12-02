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
  Elemento(int peso, int valor) : peso(peso), valor(valor), cantidad(1) {}
  Elemento(int peso, int valor, int cantidad) : peso(peso), valor(valor), cantidad(cantidad) {}
};

int min(int a, int b)
{
  return a <= b ? a : b;
}

void mochilaDP(Elemento **vecElem, int cantElementos, int topeMochila)
{
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
  mochilaDP(vecElem, cantElementos, topeMochila);
  return 0;
}