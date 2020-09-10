#include <iostream>
#include <unistd.h>

using namespace std;

void suma(int *numero)
{
    *numero += 1;
}

int main()
{
    int *numero = new int;
    cin >> *numero;

    suma(numero);

    cout << *numero << endl;
    free(numero);
}