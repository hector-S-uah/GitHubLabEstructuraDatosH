#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include <iostream>
#include "Persona.hpp"
using namespace std;

class NodoPila
{
public:
    NodoPila(int v, NodoPila* sig = NULL);
    ~NodoPila();

private:
    int valor;
    NodoPila* siguiente;
    friend class Pila; // permite acceder a los atributos privados (no abusar de friend class)
};

typedef NodoPila* pnodoPila;

#endif