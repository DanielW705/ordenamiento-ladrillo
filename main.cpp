/******Descripcion del tema*********
Uso de metodo parity o ladrillo o de pares y nones
Esta manera de ordenamiento, funciona igual que el metodo burbuja solo que los pares se colocan del lado izquierdo y impares derecho
En este no importa como se ordene (de mayor a menor) solo se ordena de pares a impares
**************/
/*********Librerias******/
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
/*********Usings************/
using namespace std;
/**********Prototipos****************/
void randomNumbers();
void ParitySort();
void imprimir();
void swuap(int *, int *);
/*********Variables Globales********/
// Este length es el tamaño del arreglo me dio hueva hacer una estructura
int length = 10;
// Declaramos arreglo dinamico
int *numeros = new int[0];
/*************Funcion Main**********/
int main(int argc, char const *argv[])
{
    /********Variables locales*****/
    /*****************************/
    /****asi se llama a una FUNCION SIN PARAMETROS****/
    randomNumbers();
    ParitySort();
    imprimir();
    /*********El metodo o funcion clock de la libreria ctime (en c++), o time.h (en c), da el tiempo desde que inicia el programa.***/
    cout << "Tiempo de ejecucion: " << clock() << "ms" << endl;
    /***Getch este metodo cuando das click cualquier caracter del teclado***/
    getch();
    return 0;
}
/****************Metodos o funciones************/
void randomNumbers()
{
    // Rand es un metodo de cstdlib (en c++), y stdlib.h (en c), se divide entre 100 para que de un numero entre 0 y 100, y se le suma para que de entre 1 y 100.
    // length = rand() % 1000 + 1;
    *&numeros = new int[length];
    cout << "Arreglo desordenado: ";
    for (int i = 0; i < length; i++)
    {
        *&numeros[i] = rand() % 10;
        cout << *&numeros[i] << (i >= (length - 1) ? "" : ",");
    }
    cout << endl;
}
void ParitySort()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if ((*&numeros[j] & 1) == 1 && (*&numeros[j + 1] & 1) == 0)
            {
                swap(*&numeros[j + 1], *&numeros[j]);
            }
            else if ((*&numeros[j] & 1) == 0 && (*&numeros[j + 1] & 1) == 0)
            {
                if (*&numeros[j] > *&numeros[j + 1])
                    swap(*&numeros[j + 1], *&numeros[j]);
            }
            else if ((*&numeros[j] & 1) == 1 && (*&numeros[j + 1] & 1) == 1)
            {
                if (*&numeros[j] > *&numeros[j + 1])
                    swap(*&numeros[j + 1], *&numeros[j]);
            }
        }
    }
    // int aux = 0;
    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = 0; j < length - 1; j++)
    //     {
    //         int num1 = *&numeros[j];
    //         int num2 = *&numeros[j + 1];
    //         if ((num1 & 1) == 1) // Este modo de condicional usa binarios, este dice "num1 and 1" si esto se cumple devolvera un uno por lo cual se puede decir que es impar, pudes usar tambien el "num % 2 == 0" este dara el residuo, y si el residuo es 0 significa que es para
    //         {
    //             aux = num1;
    //             *&numeros[j] = num2;
    //             *&numeros[j + 1] = aux;
    //         }
    //         else{

    //         }
    //     }
    // }
}
void imprimir()
{
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < length; i++)
    {
        cout << *&numeros[i] << (i >= (length - 1) ? "" : ",");
    }
    cout << endl;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}