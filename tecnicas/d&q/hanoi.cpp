#include <iostream>

using namespace std;

void hanoi(int n, char origen, char destino, char intermedio, int &count)
{
  if (n > 0)
  {
    hanoi(n - 1, origen, intermedio, destino, count);

    cout << "Muevo de " << origen << " a " << destino << endl;
    count++;
    hanoi(n - 1, intermedio, destino, origen, count);
  }
}

int main()
{
  int n = 10, count = 0;
  hanoi(n, 'A', 'B', 'C', count);
  cout << "Cantidad de movimientos: " << count << endl;
  return 0;
}