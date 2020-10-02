#include <iostream>

using namespace std;

// método burbuja
void sort(int *v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (v[j] < v[i]) 
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main () 
{
    int n;
    cin >> n;

    int *vec = new int[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> vec[i];
    }

    sort(vec, n);

    for (int i = 0; i < n; i++) 
    {
        cout << vec[i] << " ";
    }

    return 0;
}