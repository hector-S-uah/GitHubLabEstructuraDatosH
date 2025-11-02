#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>
#include "Aficionado.hpp"
using namespace std;
class NodoCola
{
public:
	NodoCola(Aficionado* aficionado, NodoCola*sig=NULL);
	~NodoCola();
private:
	Aficionado* aficionado;
	NodoCola*siguiente;
	friend class Cola;
};
typedef NodoCola* pnodoCola;
#endif // NODOCOLA_HPP
