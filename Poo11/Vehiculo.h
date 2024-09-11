#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
using namespace std;

// Este archivo es el encabezado 
// Contiene la declaracion de atributos y metodos

class Vehiculo {
private: // Atributos
	int anio;
	int capDepo;
	int litrosDepo;
	int kph;
	string propietario;

public:	// Metodos
	Vehiculo();  // Constructor por defecto
	Vehiculo(int _anio, int _capDepo, int _litrosDepo, int _kph, string _propietario);  // Constructor con parámetros
	Vehiculo(const Vehiculo& vehiculo);  // Constructor de copia


	virtual void imprimir();
	void llenarDepo();

	//Setter y Getters
	void setAnio(int a) { anio = a; }
	int getAnio() const { return anio; }

	void setCapDepo(int c) { capDepo = c; }
	int getCapDepo() const { return capDepo; }

	void setLitrosDepo(int s) { litrosDepo = s; }
	int getLitrosDepo() const { return litrosDepo; }

	void setKph(int k) { kph = k; }
	int getKph() const { return kph; }
	
	void setPropietario(string p) { propietario = p; }
	string getPropietario() const { return propietario; }
};
#endif // VEHICULO_H