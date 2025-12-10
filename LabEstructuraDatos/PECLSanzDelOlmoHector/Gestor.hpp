#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Cola.hpp"
#include "Lista.hpp"
#include "Pila.hpp"
#include "Arbol.hpp"
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
	void construirArbol();
	void dibujarArbol();
	void crearYDibujarArbol();
	void mostrarSociosAbb();
	void mostrarSimpatizantesAbb();
	void mostrarAficionadosAbb();
	void eliminarAficionado(int ID);
	void buscarAbb();
	void contarParesAbb();
	void mostrarHojasAbb();
	
    int AficionadosEnPila();   // hecho
    int SociosEnCola();        // hecho
    int SimpatizantesEnCola(); // hecho
	int AficionadosEnLista();
	int AficionadosEnArbol();
	

private:
    Pila pilaAficionados;
    int ronda;
    Cola colaSocios;
    Cola colaSimpatizantes;
	Lista listaOrdenada;
	Arbol abbAficionados;
};

#endif // GESTOR_HPP
