class Tripleta
{
public:
  int inicio, fin, altura;
  Tripleta(int inicio, int fin, int altura) : inicio(inicio), fin(fin), altura(altura) {}
};

class Tupla
{
public:
  int pos, altura;
  Tupla(int pos, int altura) : pos(pos), altura(altura) {}
};

class Silueta
{
public:
  Tupla **tuplas;
  int largo;
  Silueta(Tupla **tuplas, int largo) : tuplas(tuplas), largo(largo) {}
};

Silueta *siluetasDC(Tripleta **vec, int largo, int desde, int hasta)
{
  if (desde == hasta)
  {
    Tupla **tuplas = new Tupla *[2];
    tuplas[0] = new Tupla(vec[desde]->inicio, vec[desde]->altura);
    tuplas[1] = new Tupla(vec[desde]->fin, 0);
    return new Silueta(tuplas, 2);
  }
  else
  {
    int medio = (desde + hasta) / 2;
    Silueta *siluetasDCIzq = siluetasDC(vec, largo, desde, medio);
    Silueta *siluetasDCDer = siluetasDC(vec, largo, medio + 1, hasta);
    // MERGE! CONQUER! CONQUISTAR!
  }
}