#ifndef Coche_H
#define Coche_H
#include "Vehiculo.h"
#include <string>
using namespace std;


class Coche : public Vehiculo {
private:
	int numAsientos;
	string marca;

public:
	Coche(); // Constructor por defecto
	Coche(int _anio, int _capDepo, int _litrosDepo, int _kph, string _propietario, int _numAsientos, string _marca); // Constructor con parámetros
	Coche(const Coche& coche); // Constructor de copia

	void imprimir() override;


	//Setter y getters
	void setCilindrada(int c) { numAsientos = c; }
	int getCilindrada() const { return numAsientos; }


	void setTipo(string t) { marca = t; }
	string getTipo() const { return marca; }

};
#endif Coche_H