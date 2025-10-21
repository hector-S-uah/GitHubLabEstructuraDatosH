#include "NodoPila.hpp"

NodoPila::NodoPila(Aficionado* aficionado, NodoPila*sig)
{
	this->aficionado=aficionado;
	siguiente=sig;
}

NodoPila::~NodoPila()
{
}

