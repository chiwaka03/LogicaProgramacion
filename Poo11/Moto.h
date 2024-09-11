#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"
#include <string>
using namespace std;

class Moto : public Vehiculo {
private:
    int cilindrada;
    string tipo;

public:
    Moto(); // Constructor por defecto
    Moto(int _anio, int _capDepo, int _litrosDepo, int _kph, string _propietario, int _cilindrada, string _tipo); // Constructor con par�metros
    Moto(const Moto& moto); // Constructor de copia

    // M�todos
    void imprimir() override; // M�todo para imprimir los detalles del Moto

    // Setters y Getters
    void setCilindrada(int c) { cilindrada = c; }
    int getCilindrada() const { return cilindrada; }

    void setTipo(string& t) { tipo = t; }
    string getTipo() const { return tipo; }
};

#endif // MOTO_H