// Mochila 0-N

#include <cstring>
#include <iostream>
#include <fstream>
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

void mochilaBT(Elemento **vecElem, int cantElementos, int posElem, int topeMochila, Elemento **solActual, int valActual, Elemento **&solOptima, int &valOptimo, int &pesoOptimo)
{
  // Procesé a todos los elementos!
  if (posElem == cantElementos)
  {
    // Mi solución es mejor
    if (valActual > valOptimo || (valActual == valOptimo && topeMochila > pesoOptimo))
    {
      // Actualizo el mejor valor y las combinaciones que me llevaron al mismo
      valOptimo = valActual;
      for (int i = 0; i < cantElementos; i++)
      {
        solOptima[i]->cantidad = solActual[i]->cantidad;
      }
      pesoOptimo = topeMochila;
    }
  }
  else
  {
    for (int k = 0; k <= vecElem[posElem]->cantidad; k++)
    {
      topeMochila -= vecElem[posElem]->peso * k;
      if (topeMochila >= 0)
      {
        solActual[posElem]->cantidad += k;
        valActual += vecElem[posElem]->valor * k;
        mochilaBT(vecElem, cantElementos, posElem + 1, topeMochila, solActual, valActual, solOptima, valOptimo, pesoOptimo);
        valActual -= vecElem[posElem]->valor * k;
        solActual[posElem]->cantidad -= k;
      }
      else
        break;
      topeMochila += vecElem[posElem]->peso * k;
    }
  }
}

int main()
{
  ifstream myFile("testMochila0N.in.txt");
  cin.rdbuf(myFile.rdbuf());
  ofstream myFile2("out.txt");
  cout.rdbuf(myFile2.rdbuf());

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
    int cantidad;
    cout << "Cantidad: " << endl;
    cin >> cantidad;
    vecElem[i] = new Elemento(peso, valor, cantidad);
    solActual[i] = new Elemento(peso, valor, 0);
    solOptima[i] = new Elemento(peso, valor, 0);
  }
  int topeMochila;
  cout << "Tope mochila:" << endl;
  cin >> topeMochila;
  cout << endl;
  int valOptimo = 0;
  int pesoOptimo = 0;
  mochilaBT(vecElem, cantElementos, 0, topeMochila, solActual, 0, solOptima, valOptimo, pesoOptimo);

  for (int i = 0; i < cantElementos; i++)
  {
    if (solOptima[i]->cantidad > 0)
    {
      cout << "Cantidad del elemento " << i << " (Peso: " << solOptima[i]->peso << ", valor: "
           << solOptima[i]->valor << "): " << solOptima[i]->cantidad << endl;
    }
  }
  cout << "Valor total: " << valOptimo << endl;
  cout << "Peso optimo: " << pesoOptimo << endl;
  return 0;
}