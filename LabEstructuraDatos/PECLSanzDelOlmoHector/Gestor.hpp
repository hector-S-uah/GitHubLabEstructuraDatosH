#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Cola.hpp"
#include "Lista.hpp"
#include "Pila.hpp"

#include <algorithm>

class Gestor
{
public:
    Gestor();
    ~Gestor();

    void genera10Aficionados();      // hecho
    void muestraAficionados();       // hecho
    void borraAficionadosPila();     // hecho
    void encolarAficionados();       // hecho
    void muestraSociosCola();        // hecho
    void muestraSimpatizantesCola(); // hecho
    void borraAficionadosColas();    // hecho
    void enlistarAficionados();
    void buscarAficionados();
    void reiniciar();
    int AficionadosEnPila();   // hecho
    int SociosEnCola();        // hecho
    int SimpatizantesEnCola(); // hecho
	int AficionadosEnLista();

private:
    Pila pilaAficionados;
    int ronda;
    Cola colaSocios;
    Cola colaSimpatizantes;
	Lista listaOrdenada;
};

#endif // GESTOR_HPP
