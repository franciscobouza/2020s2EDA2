#include <iostream>

using namespace std;

int *calcularGradosEntrantes(bool **matAdy, int largo)
{
  int *gradosEntrantes = new int[largo];
  for (int j = 0; j < largo; j++)
  {
    int suma = 0;
    for (int i = 0; i < largo; i++)
    {
      if (matAdy[i][j])
      {
        suma++;
      }
    }
    gradosEntrantes[j] = suma;
  }
  return gradosEntrantes;
}

int obtenerVerticeGradoEntranteCero(int *gradosEntrantes, int largo)
{
  for (int i = 0; i < largo; i++)
  {
    if (gradosEntrantes[i] == 0)
    {
      return i;
    }
  }
  return -1;
}

void ordenTopologico(bool **matAdy, int *vertices, int largo)
{
  int *gradosEntrantes = calcularGradosEntrantes(matAdy, largo);
  for (int k = 0; k < largo; k++)
  {
    int posCero = obtenerVerticeGradoEntranteCero(gradosEntrantes, largo);
    if (posCero == -1)
    {
      cout << "HAY CICLO!" << endl;
      return;
    }
    else
    {
      cout << vertices[posCero] << endl;
      gradosEntrantes[posCero] = -1;
      for (int j = 0; j < largo; j++)
      {
        if (matAdy[posCero][j])
        {
          gradosEntrantes[j]--;
        }
      }
    }
  }
}