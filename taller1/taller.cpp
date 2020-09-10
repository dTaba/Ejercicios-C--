#include "taller.h"
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <iostream>
// ACLARACION: Todas las funciones devuelven algo del tipo necesario, esto es para que no explote cuando 
// vayan compilando (y de paso para que no se olviden de devolver el tipo correcto)


// Ejercicio 0
// Dado un vector v, devuelve el valor maximo encontrado.
// Se puede hacer en una línea (pero no lo hagan, no vale)
// HINT: Para saber la cantidad de elementos de un vector, usar v.size()
using namespace std;
int mayor(vector<int> v)
{
	int aux = 0;
	
	for(int i = 0; i <= v.size()-1; i++)
	{
		if(v[i] > aux)
		{
			aux = v[i];
		}
	}

	return aux;
}

// Ejercicio 1 
// Dado un vector v, devuelve el reverso.
// Se puede hacer en una línea (pero no lo hagan, no vale)

vector<int> reverso(vector<int> v)
{
	vector<int> reverso;

	for(int i = 0; i <= v.size()-1; i++)
	{
		reverso.push_back(v[v.size()-1-i]);
	}

	return reverso;
}

// Ejercicio 2
// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
vector<int> rotar(vector<int> v, int k)
{
	vector<int> rotado(v.size());
	
	for(int i = 0; i <= v.size()-1; i++)		
	{
		if (i<k)
		{
			rotado[v.size() + i - k ] = v[i];
		}
		else
		{	
			rotado[i-k] = v[i];
		}
	}
// en ningun lugar decia que tenia que usar pushback y bueno colgue
	return rotado;
}

// Ejercicio 3
// Dado un vector v, hacer una función que lo modifique sumandole uno a todos sus elementos
// Determinar la cabecera de la funcion y definir taller.h !!
vector<int> sumarUno(vector<int> v)
{
	for(int i = 0; i <= v.size()-1; i++)
	{
		v[i] = v[i] + 1;
	}
	return v;
}


// Ejercicio 4
// Dado un vector v de int, dice si esta ordenado(ya sea creciente o decrecientemente)
bool estaOrdenado(vector<int> v)
{
	bool ordenado = true;
	string keyword = "";
	if (v[1] > v[0])
	{
		keyword = "Ascendente";
	}
	else if (v[1] < v[0])
	{
		keyword = "Descendente";
	}
	else if (v[1] == v[0])
	{
		for(int i = 2; i<= v.size()-1;i++)
		{
			if (v[i] > v[i-1])
			{
				keyword = "Ascendente";
				break;
			}
			else if (v[i] < v[i-1])
			{
				keyword = "Descendente";
				break;
			}
			else if (i = v.size()-1)
			{
				if(keyword == "")
				{
					cout << "Son todos iguales" << endl;
					return false;
				}
			}
						
		}
	}


	if(keyword == "Ascendente")
	{
		for(int i = 1; i<= v.size()-1;i++)
		{
			if(v[i] < v[i-1])
			{
				return false;
			}
		}
	} 
	else if (keyword == "Descendente")
	{
		for(int i = 1; i<= v.size()-1;i++)
		{
			if(v[i] > v[i-1])
			{
				return false;
			}
		}
	}
	return true;
}


// Ejercicio 5
// Dado un vector de enteros muestra por la salida estándar, el vector
// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]

// HINT: Esta función es general, out es del tipo de dato ostream. 
// Eso significa que el parametro out puede ser cout (si quiero escribirlo a la consola)
// o bien podrías ser un archivo de texto. En cualquier caso puedo usar el operador << para escribir.

void mostrarVector(vector<int> v, ostream& out)
{	
	out << "["; 
	for(int i= 0; i <= v.size()-1;i++)
	{
		out << v[i];
		if(!(i==v.size()-1))
		{
			cout << ", ";
		}
	}	
	out << "]"; 
	return;
}

// Ejercicio 6 
// Dado un vector de enteros y el nombre de un archivo de salida,
// escribe al vector en el archivo. Ejemplo: si el vector es <1, 2, 5, 65>
// el archivo contiene [1, 2, 5, 65]
// Ojo con el constructor de ofstream. Es importante hacer la conversion del string a char* usando c_str().
// Reutilizar la función anterior!

void guardarVector(vector<int> v, string nombreArchivo)
{
	// Abro un archivo con el nombre dado por parámetros (c_str() convierte string a un "string" de C)
   ofstream file(nombreArchivo.c_str());
   if(file.is_open())
   {
   		mostrarVector(v, file);
		file.close();
   }
   return;
}


//Ejercicio 7 
// Dado un archivo que contiene una lista de números, contar la cantidad de
// apariciones de cada uno y escribir nombreArchivoOut con una linea por cada
// numero encontrado, un espacio y la cantidad de apariciones
// El parametro max indica el número más grande que puede aparecer en el archivo
// Ejemplo: si el 1 aparece 44 veces y el 2 20 veces (y no hay otros numeros) en la salida deberia
// haber dos lineas, la primera con "1 44" y la segunda "2 20"

void cantidadApariciones(string nombreArchivo, string nombreArchivoOut)
{
	//Variables

	vector<string> datos;
	vector<string> numeros;

	string numero;

	//Lectura

	ifstream fileIn(nombreArchivo.c_str());

	if(fileIn.is_open())
	{
		while(getline(fileIn, numero , ' '))
		{
			datos.push_back(numero);
		}
		fileIn.close();
	}

	//Debugging

	// for(int j = 0; j <= datos.size() - 1;j++)
	// {
	// 	cout << datos[j] << " ";
	// }

	for(int i = 0; i <= datos.size() - 1 ; i++)
	{
		numeros.push_back(datos[i]);	

		if (numeros.size() >= 2)
		{
			for(int x = 0; x <= numeros.size() -2; x++)
			{	
				if(numeros[x] == datos[i])
				{
					numeros.erase(numeros.begin()+i);
				}
			}
		} 

	}
	
	vector<int> apariciones(numeros.size(),0);
	
	// for(int i = 0; i <= datos.size() - 1 ; i++)
	// {
	// 	apariciones[i]++;
		
	// 	for(int x = 0; x <= numeros.size() -1; x++)
	// 	{	
	// 		if(datos[i] == numeros[x])
	// 		{
	// 			apariciones[x]++;
	// 			break;
	// 		}
	// 	}

	// }

	for(int i = 0; i <= datos.size() - 1 ; i++)
	{	

		if (numeros.size() >= 2)
		{
			for(int x = 0; x <= numeros.size() -2; x++)
			{	
				if(numeros[x] == datos[i])
				{
					apariciones[x]++;
				}
			}
		} 

	}



	//Escritura

	ofstream fileOut(nombreArchivoOut.c_str());
    
	if (fileOut.is_open())
	{
		for(int h = 0; h <= numeros.size()-1;h++)
		{
			fileOut << numeros[h] << " " << apariciones[h] << endl;
		}
	}
	
	return;    
}


//Ejercicio 8 (opcional)
//Dado un archivo de texto, lo filtra y devuelve los palindromos en el archivo salida, uno por linea.
void palindromos(string nombreArchivo, string nombreArchivoOut)
{
	return;	
}
