#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include <iostream>
using namespace std;
class Cola
{
public:
	Cola();
	~Cola();
	void insertar(Aficionado* aficionado);
	Aficionado* extraer();
	void mostrar();
	int getLongitud();
	bool esVacia();
	void vaciarCola();
private:
	pnodoCola primeroCola, ultimoCola;
	int longitud;
};

#endif // COLA_HPP
