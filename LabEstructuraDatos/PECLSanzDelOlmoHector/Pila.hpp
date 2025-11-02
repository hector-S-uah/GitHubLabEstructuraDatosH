#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include <iostream>
using namespace std;
class Pila
{
public:
	Pila();
	~Pila();
	
	void insertar(Aficionado*aficionado);
	Aficionado*extraer();
	Aficionado*cima();
	void mostrar();
	int getLongitud();
	bool esVacia();
	void vaciarPila();
	
private:
	pnodoPila ultimoPila;
	int longitudPila;
	

};

#endif // PILA_HPP
