int fhash(int val, int largo)
{
  return val % largo;
}

int fhashStr(string val, int largo)
{
  int suma = 0;
  for (int i = 0; i < val.length; i++)
  {
    suma += val[i];
  }
  return suma % largo;
}

bool esPrimo(int num)
{
  if (num < 2)
    return false;
  for (int i = 2; i <= num / 2; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}

int primoSup(int num)
{
  while (!esPrimo(num + 1))
  {
    num++;
  }
  return num + 1;
}

//Ganadores de la módica suma de 1 puntito:
- Lucía - Agustín Ferrari