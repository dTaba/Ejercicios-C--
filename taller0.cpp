
#include <iostream>
#include <math.h>
#include<stdio.h>
#include <cmath>
#include "taller.h"
#include <cctype>
#include <cstring>



using namespace std;
/* IMPORTANTE: <math.h> y <cmath> se incluyen
 * solo para que utilicen abs() y pow(),
 * si las neceistaran. */



// Ejercicio 0
// Dados enteros a y b, decide si 'a' divide a 'b'.
bool divide(int a, int b)
{
    if (b % a == 0)
    {
        return true;
    }
    else
    {
        
        return false;
    }
    
    return true;
}

// Ejercicio 1
// Dados dos enteros a y b, devuelve el mayor.
 int mayor(int a, int b)
{
    return a > b ? a : b;
}

// Ejercicio 2
// Dado un n, devuelve el factorial de n.
unsigned int factorialPorCopia(int n)
{
    int fact=1;

    for(int i = 1; i <= n; i++)
    {
        fact = fact*i;
    }

   return fact;
}


// Ejercicio 3
// Dado un n por teclado, imprimir el factorial de n por pantalla.
// Hint: Usar la función anterior
void factorialPorTeclado()
{
    int a;
    cin >> a;
    cout << factorialPorCopia(a) << endl;
}

//Ejercicio 4
// Dado un n por teclado, devuele true si y solo sí n es primo
bool esPrimo(int n)
{   
    bool esprimo = true;
    for(int i=2; i <= n-1 ; i++)
    {
        
        if(n%i==0)
        {   
            esprimo = false;
            break;
        }
    }
   return esprimo;
}

// Ejercicio 5
// Dado un n, devolver los primos gemelos menores o iguales a n.
// Dos numeros son primos gemelos si son primos y están a distancia 2.
// Q y P son primos gemelos si P=Q+2, por ejemlo 3 y 5, 5 y 7, 11 y 13...

bool primoGemelo(int n)
{  
    // int numeroprimoencontrado=0;

    // for(int i = 3; i <= n; i++) // Numeros del 1 al 100
    // {
    //     for(int x = 2; x<=i ; x++) // Los anteriores del numero elegido para ver si es primo
    //      {
    //          if(i%x == 0)
    //          {  
    //              break;
    //          }
            

    //          if (x == i-1)
    //          {
    //              numeroprimoencontrado=i;
    //              if(i - numeroprimoencontrado == 2)
    //              {
    //                  cout << i << endl;
    //              }
    //          }
    //      }

    //  }
     return true;
// profe lo empece a hacer para esta consigna y desp me di cuenta que la cambiaste y me frustre xd
}


// Ejercicio 6
// Dado un numero capturado por teclado, decidir si es un palindromo.
// Por ejemplo: la entrada "hola mundo", deberia dar por resultado:
// "Numero: NO, Palindromo: NO". Mientras que "severlasalreves" deberia dar 
// "Numero: NO, Palindromo: SI"
// Hint: Ver las funciones at del tipo string y isdigit.

void esCapicua(string s)
{
    string numero;
    bool palindromo=true;
    int letras = s.length();



    for(int i=0; i<= letras -1 ;i++)
    {
        if(isdigit(s[i]) == false)
        {
            numero = "No";
            
        }
        else
        {
            numero = "Si";
            break;
        }
        
    }

    for(int i=0 ;i <= letras-1 ;i++)
    {

        if(s[i] != s[letras-1-i])
        {
            palindromo = false;
            break;
        }
    }

    if(palindromo == false)
    {   
        cout << "No es palindromo" << endl;
        cout << numero << " es un numero" <<endl;
    }
    else
    {
        cout << "Es palindromo" << endl;
        cout << numero << " es un numero" <<endl;
    }
}


// Ejercicio 7
// Dado un n, voy a escribir la secuencia de numeros de 0 a n
// Por ejemplo, n=4, da 0,1,2,3,4

void numerosHasta(int n)
{
    int i = 0;
    while( i <= n)
    {
        printf("%d ", i);
        i++;
    }
    
}

// Ejercicio 8
// Dado un n, escribir por pantalla una escalera desde 0 hasta n.
// Ejemplo: n=3, deberia mostrar:
// 0
// 0 1
// 0 1 2
// 0 1 2 3
// Hint: Usar la función anterior

void escaleraSimple(int n)
{
    for(int i=0; i <= n; i++)
    {   
        numerosHasta(i);
        printf("%d \n",i);
    }
}



// Ejercicio 9
// Dado un 'n', dice si es numero perfecto o no
// Los numeros perfectos son enteros tales que su valor
// es igual a la suma de sus divisores
// Por ejemplo, 6 = 3+2+1... 28=1+2+4+7+14, etc...

bool esPerfecto(int n)
{
    int suma=0;
    for (int i=1; i<n; i++)
    {
        if (n%i==0)
        {
            suma = suma +i;
        }
    }
    if (n==suma)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

// Ejercicio 10 (opcional)
// Dado un n capturado por teclado, imprimir el triangulo de pascal de grado n
// Por ejemplo, para n=5, deberia dar
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
void pascal()
{

}


// Ejercicio 11 (opcional)
// Dado un k positivo, devolver el k-esimo numero de la susesion de fibonacci.
long fibonacci(int k)
{
    return 3;
}

// Ejercicio 12 (opcional)
// Dado un n PAR capturado por teclado, intenta ver si la Conjetura de Golbach es valida para ese n.
// Golbach dijo que todo entero n PAR estrictamente mayor a dos es expresable como
// la suma de dos numeros primos(se puede repetir el primo).
// Por ejemplo, 10=3+7, 1984=107+1877, etc...

void golbach()
{


}
