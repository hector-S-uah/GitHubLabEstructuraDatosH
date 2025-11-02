#include "NodoPila.hpp"

NodoPila::NodoPila(Aficionado* aficionado, NodoPila*sig)
{
	this->aficionado=aficionado;
	this->siguiente=sig;
}

NodoPila::~NodoPila()
{
}

