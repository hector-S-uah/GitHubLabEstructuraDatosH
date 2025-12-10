#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Aficionado.hpp"
class NodoArbol
{
public:
	NodoArbol(Aficionado* aficionado);
	~NodoArbol();
private:
Aficionado* aficionado;
NodoArbol* izq;
NodoArbol* der;

friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
