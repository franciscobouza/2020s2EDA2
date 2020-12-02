
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool esAceptable(int posX, int posY, int **tablero)
{
  return posX >= 0 && posY >= 0 && posX < 8 && posY < 8 && tablero[posX][posY] == -1;
}

void movCaballos(int posX, int posY, int cant, int **tablero, bool &exito, int *vx, int *vy)
{
  cout << cant << endl;
  if (cant == 64)
  {
    exito = true;
  }
  else
  {
    for (int k = 0; k < 8 && !exito; k++)
    {
      int nuevaPosX = posX + vx[k];
      int nuevaPosY = posY + vy[k];
      if (esAceptable(nuevaPosX, nuevaPosY, tablero))
      {
        tablero[nuevaPosX][nuevaPosY] = cant + 1;
        movCaballos(nuevaPosX, nuevaPosY, cant + 1, tablero, exito, vx, vy);
        tablero[nuevaPosX][nuevaPosY] = -1;
      }
    }
  }
}

int main()
{

  int vx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
  int vy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

  int posX, posY;
  cout << "Ingrese pos X" << endl;
  cin >> posX;
  cout << "Ingrese pos Y" << endl;
  cin >> posY;

  int **tablero = new int *[8];
  for (int i = 0; i < 8; i++)
  {
    tablero[i] = new int[8];
    for (int j = 0; j < 8; tablero[i][j++] = -1)
      ;
  }

  bool exito = false;
  tablero[posX][posY] = 1;
  movCaballos(posX, posY, 1, tablero, exito, vx, vy);

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cout << tablero[i][j] << "\t";
    }
    cout << endl;
  }
  return 0;
}