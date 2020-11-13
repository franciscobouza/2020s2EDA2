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
  Elemento(int peso, int valor) : peso(peso), valor(valor), cantidad(1) {}
  Elemento(int peso, int valor, int cantidad) : peso(peso), valor(valor), cantidad(cantidad) {}
};

void mochilaBT(Elemento **vecElem, int cantElementos, int posElem, int topeMochila, Elemento **solActual, int valActual, Elemento **&solOptima, int &valOptimo)
{
  // Procesé a todos lols elementos!
  if (posElem == cantElementos)
  {
    // Mi solución es mejor
    if (valActual > valOptimo)
    {
      // Actualizo el mejor valor y las combinaciones que me llevaron al mismo
      valOptimo = valActual;
      for (int i = 0; i < cantElementos; i++)
      {
        solOptima[i]->cantidad = solActual[i]->cantidad;
      }
    }
  }
  else
  {
    // Uso 0 elementos del elemento actual
    mochilaBT(vecElem, cantElementos, posElem + 1, topeMochila, solActual, valActual, solOptima, valOptimo);
    // Uso una vez a mi elemento actual
    solActual[posElem]->cantidad++;
    valActual += vecElem[posElem]->valor;
    topeMochila -= vecElem[posElem]->peso;
    mochilaBT(vecElem, cantElementos, posElem + 1, topeMochila, solActual, valActual, solOptima, valOptimo);
    solActual[posElem]->cantidad--;
  }
}

int main()
{
  int cantElementos;
  cout << "Cantidad de elementos:" << endl;
  cin >> cantElementos;
  cout << endl;
  Elemento **vecElem = new Elemento *[cantElementos];
  Elemento **solActual = new Elemento *[cantElementos];
  Elemento **solOptima = new Elemento *[cantElementos];
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
    solActual[i] = new Elemento(peso, valor, 0);
    solOptima[i] = new Elemento(peso, valor, 0);
  }
  int topeMochila;
  cout << "Tope mochila:" << endl;
  cin >> topeMochila;
  cout << endl;
  int valOptimo = 0;
  mochilaBT(vecElem, cantElementos, 0, topeMochila, solActual, 0, solOptima, valOptimo);

  for (int i = 0; i < cantElementos; i++)
  {
    if (solOptima[i]->cantidad > 0)
    {
      cout << "Cantidad del elemento " << i << " (Peso: " << solOptima[i]->peso << ", valor: "
           << solOptima[i]->valor << "): " << solOptima[i]->cantidad << endl;
    }
  }
  cout << "Valor total: " << valOptimo << endl;
}