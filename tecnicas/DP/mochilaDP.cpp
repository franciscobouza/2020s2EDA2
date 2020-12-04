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

int max(int a, int b)
{
  return a >= b ? a : b;
}

void mochilaDP(Elemento **vecElem, int cantElementos, int topeMochila)
{
  int **mat = new int *[cantElementos];
  for (int i = 0; i < cantElementos; mat[i++] = new int[topeMochila + 1])
    ;

  // Inicializo la primer columna
  for (int i = 0; i < cantElementos; mat[i++][0] = 0)
    ;

  // Inicializo la primer fila
  for (int j = 0; j <= topeMochila; j++)
  {
    mat[0][j] = vecElem[0]->peso <= j ? vecElem[0]->valor : 0;
  }

  // Proceso el resto de la matriz
  for (int i = 1; i < cantElementos; i++)
  {
    for (int j = 1; j <= topeMochila; j++)
    {
      if (vecElem[i]->peso > j)
      {
        // No entra el elemento
        mat[i][j] = mat[i - 1][j];
      }
      else
      {
        // Al entrar, consumo uno e indico qué es lo que mejor puedo hacer con el peso que me queda
        mat[i][j] = max(mat[i - 1][j], vecElem[i]->valor + mat[i - 1][j - vecElem[i]->peso]);
      }
    }
  }
  cout << "Valor mochila: " << mat[cantElementos - 1][topeMochila] << endl;

  // Muestro mochila
  for (int i = 0; i < cantElementos; i++)
  {
    for (int j = 0; j <= topeMochila; j++)
    {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }

  int i = cantElementos - 1, j = topeMochila;
  while (i != 0 && j != 0)
  {
    if (mat[i][j] != mat[i - 1][j])
    {
      cout << "Peso: " << vecElem[i]->peso << " Valor: " << vecElem[i]->valor << endl;
      j -= vecElem[i]->peso;
    }
    i--;
  }
  if (j != 0)
  {
    cout << "Peso: " << vecElem[0]->peso << " Valor: " << vecElem[0]->valor << endl;
  }
}

int main()
{

  ifstream myFile("mochilaDP.in.txt");
  cin.rdbuf(myFile.rdbuf());
  ofstream myFile2("out.txt");
  cout.rdbuf(myFile2.rdbuf());

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