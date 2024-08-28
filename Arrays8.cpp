#include <iostream>
#include <String>
#include <string.h>
using namespace std;

// Voy a utilizar variables globales para la 1 y 2
const int arraySize = 20;
const int charSize = 40;
int incompleteArray[arraySize] = {
        10, 30, 45, 33, 54,
        67, 43, 2, 12, 678,
        43, 23, 45, 67, 98
};
int completeArray[arraySize] = {
        10, 30, 45, 33, 54,
        67, 43, 2, 12, 678,
        43, 23, 23, 67, 98,
        35, 16, 48, 19, 99
};
int sortedArray[arraySize];
int temp, result;
std::string encriptStr = "abcd";

struct Amigos {
    char name[10];
    int age;
};

int burbleSort(int sortChooser) {

    switch(sortChooser)
    {
    case 1:
        // Menor a mayor
        for (int i = 0; i < arraySize - 1; i++) {
            for (int j = 0; j < arraySize - i - 1; j++) {
                if (completeArray[j] > completeArray[j + 1]) {
                    temp = completeArray[j];
                    completeArray[j] = completeArray[j + 1];
                    completeArray[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        // Mayor a menor
        for (int i = 0; i < arraySize - 1; i++) {
            for (int j = 0; j < arraySize - i - 1; j++) {
                if (completeArray[j] < completeArray[j + 1]) {
                    temp = completeArray[j];
                    completeArray[j] = completeArray[j + 1];
                    completeArray[j + 1] = temp;
                }
            }
        }
        break;
    default:
        cout << "Digito erroneo, introduce un numero del 1-5" << endl;
        break;
    }
    return 0;
}

bool palindromo(char palinChar[40]) {

    int temp = strlen(palinChar);
    int i = 0;
    int j = temp - 1;

    while (i < j) {
        if (palinChar[i] != palinChar[j]) {
            //cout << "No es un palindromo: " << palinChar[i] << " != " << palinChar[j] << endl;
            return false;
        }
        else {
            //cout << palinChar[i] << " == " << palinChar[j] << endl;
        }
        i++;
        j--;
    }

    return true;
}

int main() {
    cout << "****************************\n" << endl;
    cout << "***** Elige una opcion *****\n" << endl;
    cout << "1.- Leer 20 valores\n" << endl;
    cout << "2.- Leer 20 y ensenar\n" << endl;
    cout << "3.- Palindromo\n" << endl;
    cout << "4.- Encriptar\n" << endl;
    cout << "5.- Agenda\n" << endl;
    cout << "****************************\n" << endl;
	
    int selection;
    cin >> selection;

    switch (selection)
    {
    case 1:

        // Pedir numeros
        cout << "Introduce 5 numeros para completar el array:" << endl;
        for (int i = 15; i < arraySize; i++) {
            cout << "Posicion del array: " << i + 1 << " el numero que vas a meter: " << endl;
            cin >> incompleteArray[i];
        }

        // Suma
        for (int i = 0; i < arraySize ;i++) {
            temp = incompleteArray[i];
            result = result + temp;
        }
        cout << "El total de la suma del contenido de este array es: \n" << result << endl;

        // Valor promedio
        for (int i = 0; i < arraySize; i++) {
            temp = incompleteArray[i];
            result = result + temp;
        }
        result = result / arraySize;

        cout << "El valor promedio del array es: \n" << result << endl;

        
        // El mayor numero
        for (int i = 0; i < arraySize - 1; i++) {
            temp = incompleteArray[i];

            for (int j = i + 1; j < arraySize; j++) {
                if (temp < incompleteArray[j]) {
                    temp = incompleteArray[j];
                }
            }
        }
        cout << "El mayor numero es: \n" << temp << endl;


        // El menor numero
        for (int i = 0; i < arraySize - 1; i++) {
            temp = incompleteArray[i];

            for (int j = i + 1; j < arraySize; j++) {
                if (temp > incompleteArray[j]) {
                    temp = incompleteArray[j];
                }
            }
        }
        cout << "El menor numero es: \n" << temp << endl;
        break;
    case 2:

        // ESTE EJERCICIO NO LO TENGO MUY CLARO CREO QUE ESTA BIEN
        // Leer el array
        cout << "El array sin ordenar es: ";
        for (int i = 0; i < arraySize; i++) {
            cout << completeArray[i] << ", ";
        }

        cout << "Elige que quieres con un numero: " << endl;
        cout << "1.- Menor a mayor" << endl;
        cout << "2.- Mayor a menor" << endl;

        int sortChooser;
        cin >> sortChooser;


        burbleSort(sortChooser);        
        for (int i = 0; i < arraySize; i++) {
            cout << completeArray[i] << ", ";
        }

        break;
    case 3:
    {
        cout << "Introduce una frase para saber si es palindromo: \n" << endl;


        char palinChar[40] = "hola";
        cin >> palinChar;


        if (palindromo(palinChar)) 
        {
            cout << "La cadena es un palíndromo." << endl;
        }
        else {
            cout << "La cadena no es un palíndromo." << endl;
        }


        break;
    }
    case 4:
        cout << "La cadena a encriptar es: \n" << encriptStr << endl;

        for (int i = 0; i < encriptStr.length(); i++) {
            encriptStr[i] = encriptStr[i] + 3;
        }
        cout << "La cadena encriptada es: \n" << encriptStr << endl;

        break;
    case 5:
    {
        // Creamos a amigos
        struct Amigos amigos1 = { "Bob", 15};
        struct Amigos amigos2 = { "Patrick", 60};
        struct Amigos amigos3 = { "Angela", 30};

        struct Amigos amigos[] = { amigos1, amigos2, amigos3 };
                            // Calcula tamaño del array
        for (int i = 0; i < sizeof(amigos)/sizeof(amigos[0]); i++) {
            cout << "Nombre del " << i << " amigo: " << amigos[i].name << " y edad: " << amigos[i].age << endl;
        }


        break;
    }
    default:
        cout << "Digito erroneo, introduce un numero del 1-5" << endl;
        break;
    }

}