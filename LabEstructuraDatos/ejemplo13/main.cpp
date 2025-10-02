#include "Persona.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    Persona* personas[10];

    int edades[10];
    for(int i = 0; i < 10; i++) {
        bool genero = rand() % 2;
        int edad = 18 + i; // edades distintas entre 18 y 27
        char dni[10];
        sprintf(dni, "1234%c", 'A' + i);
        personas[i] = new Persona(edad, genero, dni);
    }

    for(int i = 0; i < 10; i++) {
        personas[i]->mostrar();
        delete personas[i];
    }

    return 0;
}
