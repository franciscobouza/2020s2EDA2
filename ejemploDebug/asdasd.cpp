#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

  // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
  ifstream myFile("in.txt");
  cin.rdbuf(myFile.rdbuf());
  // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
  ofstream myFile2("out.txt");
  cout.rdbuf(myFile2.rdbuf());

  int a, b;
  cin >> a;
  cin >> b;
  cout << a + b << endl;
  return 0;
}