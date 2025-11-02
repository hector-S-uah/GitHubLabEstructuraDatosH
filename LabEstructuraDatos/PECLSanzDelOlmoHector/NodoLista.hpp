#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Aficionado.hpp"
#include <iostream>
using namespace std;
class NodoLista
{
public:
	NodoLista(Aficionado* aficionado, NodoLista*sig=NULL, NodoLista*ant=NULL);
	~NodoLista();
private:
	Aficionado* aficionado;
	NodoLista* siguiente;
	NodoLista*anterior;
	friend class Lista;
};
typedef NodoLista* pnodoLista;
#endif // NODOLISTA_HPP
