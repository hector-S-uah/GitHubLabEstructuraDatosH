#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado* aficionado, NodoCola*sig)
{
	this->aficionado=aficionado;
	siguiente=sig;
}

NodoCola::~NodoCola()
{
}

