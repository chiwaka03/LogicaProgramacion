#include "Coche.h"
#include <iostream>

// Constructores
Coche::Coche() : Vehiculo(), numAsientos(4), marca("kawasaki") {
}

Coche::Coche(int _anio, int _capDepo, int _litrosDepo, int _kph, string _propietario, int _numAsientos, string _marca)
    : Vehiculo(_anio, _capDepo, _litrosDepo, _kph, _propietario), numAsientos(_numAsientos), marca(_marca) {
}

Coche::Coche(const Coche& coche) : Vehiculo(coche), numAsientos(coche.numAsientos), marca(coche.marca) {
}

// Método para imprimir los detalles del Moto
void Coche::imprimir() {
    Vehiculo::imprimir(); // Llama al método imprimir de la clase base
    cout << "Numero de asientos: " << numAsientos << endl;
    cout << "Marca: " << marca << endl;
}