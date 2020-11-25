// Mochila 0-1
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define INF 99999

class Coord
{
public:
  int x, y;
  Coord(int x, int y) : x(x), y(y) {}
};

bool llegueAlDestino(Coord *posActual, Coord *puertaDormitorio)
{
  return posActual->x == puertaDormitorio->x && posActual->y == puertaDormitorio->y;
}

bool esPosValida(char **casa, int largo, int ancho, Coord *posActual, bool **vis)
{
  bool estaDentroDeLaMatriz = posActual->x >= 0 && posActual->x < ancho && posActual->y >= 0 && posActual->y < largo;
  if (!estaDentroDeLaMatriz)
    return false;
  return casa[posActual->x][posActual->y] != 'P' && !vis[posActual->x][posActual->y];
}

int obtenerRuido(char piso)
{
  switch (piso)
  {
  case 'A':
    return 1;
  case 'S':
    return 3;
  case 'H':
    return 5;
  default:
    return 999999;
  }
}

int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};

void malaMiaDisculpame(char **casa, int largo, int ancho, Coord *posActual, Coord *puertaDormitorio, int ruidoMaximo, bool **vis, Coord **solActual, int largoActual, Coord **solOptima, int &largoOptimo)
{
  if (llegueAlDestino(posActual, puertaDormitorio))
  {
    ruidoMaximo -= obtenerRuido(casa[posActual->x][posActual->y]);
    if (ruidoMaximo > 0)
    {
      if (largoActual < largoOptimo)
      {
        // Copio solActual sobre solOptima
        for (int i = 0; i < largoActual; i++)
        {
          solOptima[i] = solActual[i];
        }
        largoOptimo = largoActual;
      }
    }
  }
  else
  {
    if (esPosValida(casa, largo, ancho, posActual, vis))
    {
      ruidoMaximo -= obtenerRuido(casa[posActual->x][posActual->y]);
      if (ruidoMaximo > 0)
      {
        solActual[largoActual++] = posActual;
        vis[posActual->x][posActual->y] = true;
        for (int k = 0; k < 4; k++)
        {
          Coord *posNueva = new Coord(posActual->x + vx[k], posActual->y + vy[k]);
          malaMiaDisculpame(casa, largo, ancho, posNueva, puertaDormitorio, ruidoMaximo, vis, solActual, largoActual, solOptima, largoOptimo);
        }
        largoActual--;
        vis[posActual->x][posActual->y] = false;
      }
    }
  }
}

int main()
{
  char **casa = {}; //{{'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A'}};
}