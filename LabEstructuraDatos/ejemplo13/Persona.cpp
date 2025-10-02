#include "Persona.hpp"

Persona::Persona(int edad, bool genero, const char* dni) {
    this->edad = edad;
    this->genero = genero;
    strcpy(this->dni, dni);
}

Persona::~Persona() {}

int Persona::getEdad() {
    return edad;
}

bool Persona::esMujer() {
    return genero;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::mostrar() {
    cout << "DNI: " << dni 
         << " | Edad: " << edad 
         << " | Genero: " << (genero ? "Mujer" : "Hombre") 
         << endl;
}
