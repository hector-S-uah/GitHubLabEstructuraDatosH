#include "NodoLista.hpp"

NodoLista::NodoLista(Aficionado* aficionado, NodoLista* sig, NodoLista*ant)
{
	this->aficionado=aficionado;
	this->siguiente=sig;
	this->anterior=ant;
}

NodoLista::~NodoLista()
{
}

