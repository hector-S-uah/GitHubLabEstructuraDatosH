#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Persona {
private:
    bool genero;      // 1 = Mujer, 0 = Hombre
    int edad;
    char dni[10];

public:
    Persona(int edad, bool genero, const char* dni);
    ~Persona();

    int getEdad();
    bool esMujer();
    void setEdad(int edad);
    void mostrar();
};

#endif
