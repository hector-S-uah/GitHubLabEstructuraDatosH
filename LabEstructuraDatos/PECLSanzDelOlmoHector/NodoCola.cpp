#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado* aficionado, NodoCola*sig)
{
	this->aficionado=aficionado;
	this->siguiente=sig;
}

NodoCola::~NodoCola()
{
}

