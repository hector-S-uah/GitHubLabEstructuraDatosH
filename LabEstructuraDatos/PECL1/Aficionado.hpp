#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
class Aficionado
{
public:
    Aficionado(int ID);
    int getID();
    int getHoraLlegada();
    bool esSocio();
    void mostrar();
    ~Aficionado();

private:
    int ID;          // identificador unico
    int hora; // int random que indica los minutos de la hora a la que llegan que va desde 1-59
    bool socio;    // ID par=es socio, ID impar= no es socio
};

#endif // AFICIONADO_HPP
