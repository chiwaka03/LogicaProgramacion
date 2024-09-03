#include <iostream>
#include <cstring>
using namespace std;


int longitudCadena(char* pStr) {
    int length = 0;
    while (*pStr != '\0')
    {
        cout << *pStr << ", ";
        *pStr++;     // Aumentamos la posicion para recorrer el arreglo
        length++;
    }
    cout << "\n" << length << endl;
    return length;
    /*
    cout << ptr << endl;  Arreglo entero
    cout << &ptr << endl;   Direccion de la memoria
    cout << *ptr << endl;   Caracter del arrelgo
    */
}

int main() {
    int selection;
    char str[5] = {};
    char *pStr = str;


    cout << "****************************\n" << endl;
    cout << "***** Elige una opcion *****\n" << endl;
    cout << "1.- Calcular longitud de punteros\n" << endl;
    cout << "2.- Control de memoria con punteros\n" << endl;
    cout << "****************************\n" << endl;

    cin >> selection;

    switch (selection)
    {
    case 1:
        cout << "Escribe una cadena de caracteres: " << endl;
        cin >> str;

        longitudCadena(pStr);
        break;
    case 2:
    {
        int size;
        int temp;

        cout << "Introduce un numero para marcar el tamano del arreglo: " << endl;
        cin >> size;
        int* intArray = new int[size];  //Tamaño variable, guardamos hueco en la memoria

        // Pedimos el contenido para el arreglo
        for (int i = 0; i < size; i++)
        {
            cout << "Introduce un numero para el puesto" << i + 1 << ": ";
            cin >> temp;

            intArray[i] = temp;
        }
        
        cout << "El arreglo normal: " << endl;
        // Imprimimos el arreglo
        for (int i = 0; i < size; i++) 
        {
            cout << intArray[i];
        }

        cout << "\nEl arreglo al reves: " << endl;
        // Imprimimos el arreglo al reves
        for (int i = size - 1; i >= 0; i--)
        {
            cout << intArray[i];
        }

        // Liberar memoria dinamica
        delete[] intArray;
        break;
    }
    default:
        cout << "Digito erroneo, introduce un numero del 1-2" << endl;
        break;
    }

    return 0;
}
