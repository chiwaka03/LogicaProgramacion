#include "Moto.h"
#include <iostream>
using namespace std;

// Constructores
Moto::Moto() : Vehiculo(), cilindrada(0), tipo("Desconocido") {
}

Moto::Moto(int _anio, int _capDepo, int _litrosDepo, int _kph, string _propietario, int _cilindrada, string _tipo)
    : Vehiculo(_anio, _capDepo, _litrosDepo, _kph, _propietario), cilindrada(_cilindrada), tipo(_tipo) {
}

Moto::Moto(const Moto& moto) : Vehiculo(moto), cilindrada(moto.cilindrada), tipo(moto.tipo) {
}

// M�todo para imprimir los detalles del Moto
void Moto::imprimir() {
    Vehiculo::imprimir(); // Llama al m�todo imprimir de la clase base
    cout << "Cilindrada: " << cilindrada << " cc" << endl;
    cout << "Tipo: " << tipo << endl;
}
