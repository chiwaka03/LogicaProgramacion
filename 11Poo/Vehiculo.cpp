#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo() : anio(5), capDepo(120), litrosDepo(40), kph(0), propietario("Desconocido") {
}

Vehiculo::Vehiculo(int _anio, int _capDepo, int _litrosDepo, int _kph, string _propietario)
    : anio(_anio), capDepo(_capDepo), litrosDepo(_litrosDepo), kph(_kph), propietario(_propietario) {
}

Vehiculo::Vehiculo(const Vehiculo& vehiculo)
    : anio(vehiculo.anio), capDepo(vehiculo.capDepo), litrosDepo(vehiculo.litrosDepo), kph(vehiculo.kph), propietario(vehiculo.propietario) {
}

// Método para imprimir los detalles del vehículo
void Vehiculo::imprimir() {
    cout << "Propietario: " << propietario << endl;
    cout << "Anio: " << anio << endl;
    cout << "Capacidad del deposito: " << capDepo << " litros" << endl;
    cout << "Litros actuales en el deposito: " << litrosDepo << " litros" << endl;
    cout << "Velocidad maxima: " << kph << " km/h" << endl;
}

// Método para llenar el depósito
void Vehiculo::llenarDepo() {
    if (litrosDepo < capDepo) {
        litrosDepo = capDepo;
        cout << "El deposito ha sido llenado completamente. Ahora tiene " << litrosDepo << " litros." << endl;
    }
    else {
        cout << "El deposito ya esta lleno." << endl;
    }
}