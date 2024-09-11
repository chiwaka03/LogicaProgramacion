#include <iostream>
#include <cstring>
#include "Vehiculo.h"
#include "Moto.h"
using namespace std;


int main() {
	Vehiculo v1 (1,120,4,56,"Paco");
	v1.imprimir();
	Moto m1(2024, 20, 10, 180, "Juan", 600, "Deportiva");
	m1.imprimir();

	cout << "\nDespues de llenar el deposito tienes: " << endl;
	v1.llenarDepo();
	return 0;
}
