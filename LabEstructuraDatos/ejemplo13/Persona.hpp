#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>
#include <iostream>
using namespace std;

class Persona
{
public:
    Persona(int edad);
    int getEdad();
	bool esMujer();
    void setEdad(int edad);
    void mostrar();
    ~Persona();

private:
    bool genero;
    int edad;
    char DNI[10];
    void generarDNI();
	friend class NodoPila;
};

#endif
