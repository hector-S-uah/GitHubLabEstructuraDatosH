#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include <iostream>
#include "Aficionado.hpp"
using namespace std;

class NodoPila
{
public:
	NodoPila(Aficionado*aficionado, NodoPila*sig= NULL);
	~NodoPila();
	
private:
	Aficionado*aficionado;
	NodoPila*siguiente;
	friend class Pila;	//Permite acceder a los atributos privados 
	

};
typedef NodoPila*pnodoPila;

#endif // NODOPILA_HPP
