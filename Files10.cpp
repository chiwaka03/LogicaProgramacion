#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
	std::string content;
	std::string title = "ejemplo1.txt";
	std::string shrekStr = "Shrek.jpg";

	cout << "****************************\n" << endl;
	cout << "***** Elige una opcion *****\n" << endl;
	cout << "1.- Crear, escribir y comprobar\n" << endl;
	cout << "2.- Leer\n" << endl;
	cout << "3.- Utilizamos fstream\n" << endl;
	cout << "4.- Abrir imagen en binario\n" << endl;
	cout << "5.- Modifica la anterior imagen\n" << endl;
	cout << "****************************\n" << endl;

	int selection;
	cin >> selection;

	switch (selection) {

	case 1:
	{
		std::ofstream fileWrite(title); // Creamos fichero con ofstream
		fileWrite << "Hola" << endl;
		fileWrite.close();


		std::ifstream fileRead(title);
		if (!fileRead.is_open()) {
			cout << "El archivo no existe o la ruta es incorrecta" << endl;
		}
		else {
			// Si el archivo se abrió correctamente, intentamos leer el contenido
			if (fileRead >> content) { 
				cout << "Contenido leido: " << content << endl;
			}
			else {
				cout << "El archivo esta vacio o no se pudo leer correctamente" << endl;
			}

			// Cerramos el archivo
			fileRead.close();
		}
	
	}
		break;
	case 2:
	{
		std::ifstream fileRead(title);
		if (!fileRead.is_open()) {
			cout << "El archivo no existe o la ruta es incorrecta" << endl;
		}
		else {
			// Si el archivo se abrió correctamente, intentamos leer el contenido
			if (fileRead >> content) {
				cout << "Contenido leido: " << content << endl;
			}
			else {
				cout << "El archivo esta vacio o no se pudo leer correctamente" << endl;
			}

			fileRead.close();
		}
	}
		break;
	case 3:
	{
		std::fstream fileWrite(title, std::ios::out); // Creamos fichero con fstream
		fileWrite << "Hola" << endl;
		fileWrite.close();


		std::fstream fileRead(title, std::ios::in);
		if (!fileRead.is_open()) {
			cout << "El archivo no existe o la ruta es incorrecta" << endl;
		}
		else {
			// Si el archivo se abrió correctamente, intentamos leer el contenido
			if (fileRead >> content) {
				cout << "Contenido leido: " << content << endl;
			}
			else {
				cout << "El archivo esta vacio o no se pudo leer correctamente" << endl;
			}

			// Cerramos el archivo
			fileRead.close();
		}

	}
		break;
	case 4:
	{
		char c;
		std::ifstream binaryFile(shrekStr, ios::binary);
		if (!binaryFile.is_open()) {
			cout << "El archivo no existe o la ruta es incorrecta" << endl;
		}
		else {
			//cout << "El archivo esta";
			while (binaryFile) {
				binaryFile.get(c);
				cout << c;
			}
		}
	}
		break;
	case 5:
	{
		// Utilizamos size_t para tener mas tamano 
		// Y no tengo que convertir valores
		size_t fileSize, halfSize;
		char cArray[5] = {3, 4, 7, 1, 9};	// Los array utilizan punteros
		char readArray[10];
		char c;

		std::fstream binaryFile(shrekStr, ios::binary | ios::in | ios::out);
		if (!binaryFile) {
			cout << "Error al abrir el archivo" << endl;
			return -1;
		}
		binaryFile.seekg(0, ios::end);	// Cogemos la posicion final 
		fileSize = binaryFile.tellg();
		halfSize = fileSize / 2;
		binaryFile.seekp(halfSize);

		// En el caso de los tipos primitivos
		// binaryFile.write(reinterpret_cast<char*>(&c), sizeof(c));

		if (binaryFile.write(cArray, sizeof(cArray))) {
			cout << "Se ha escrito bien" << endl;
		}
		else {
			cout << "Error al escribir" << endl;
		}
		binaryFile.seekp(halfSize -10);

		if (binaryFile.read(readArray, sizeof(readArray))) {
			while (binaryFile) {
				binaryFile.get(c);
				cout << static_cast<int>(c);
			}
		}

		binaryFile.close();		// Cerramos el archivo
	}
		break;
	default:
		cout << "Digito erroneo, introduce un numero del 1-5" << endl;
		break;
	}
	return 0;
}