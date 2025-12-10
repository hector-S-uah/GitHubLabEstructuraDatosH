#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include <iostream>
#include <algorithm> // Para max/min
#include <string>
#include <vector>
#include <sstream>   // Necesario para formatear la hora/tipo si se añaden

using namespace std;

class Arbol
{
public:

    Arbol();
    ~Arbol();

    // Gestión del Árbol y Contador
    void insertarRaizFicticia(Aficionado* ficticio);
    void insertarAficionado(Aficionado* aficionado);
    int getContador();
    bool esVacio();
    void vaciarArbol();
    
    // Opciones del Menú (Implementadas)
    void dibujar();	
    void mostrarSociosInorden();         // Opción L
    void mostrarSimpatizantesInorden();  // Opción M
    void mostrarCompletoInorden();       // Opción N
    void eliminarAficionadoPorID(int ID); // Opción R
    
    // Opciones del Menú (Pendientes de implementar la lógica en Arbol.cpp)
    void buscarAficionados(); // Opción O: primer aficionado en acceder al estadio, el último socio en acceder al estadio, el primer simpatizante en acceder al estadio y el último aficionado en acceder al estadio.
    void contarIDsPares();    // Opción P
    void mostrarAficionadosHoja(); // Opción Q

private:
    pnodoAbb raiz;
    int contador; // Contador de aficionados reales, no se cuenta el ficticio
    // La constante SEPARACION ya no se usa con el nuevo método de dibujo.
    
    // Auxiliares de Inserción
    void insertarRecursivo(pnodoAbb& nodo, Aficionado* aficionado); // Auxiliar de inserción (ABB estándar)
    
    // Auxiliares de Gestión de Memoria
    void liberarNodos(pnodoAbb nodo);

    // Auxiliares de Dibujo
    int altura(pnodoAbb nodo); // Calcula la altura del subárbol
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p, char linkChar);

    // Auxiliares de Recorrido (Inorden)
    // Permite recorrer el árbol filtrando por Socios o Simpatizantes.
    void inorden(pnodoAbb nodo, bool soloSocios, bool soloSimpatizantes);
    
    // Auxiliares de Eliminación
    void eliminarRecursivo(pnodoAbb& nodo, int ID);
	
    pnodoAbb buscarSucesor(pnodoAbb nodo); // Auxiliar para encontrar el sucesor inorden (caso 2 hijos)
	
	// Auxiliares de Búsqueda (Opcion O: Busqueda por hora)
    void buscarExtremosRecursivo(pnodoAbb nodo, Aficionado*& primerAficionado, Aficionado*& ultimoSocio, Aficionado*& primerSimpatizante, Aficionado*& ultimoAficionado);
    
    // Auxiliares de Conteo (Opcion P)
    void contarParesRecursivo(pnodoAbb nodo, int& contadorPares);

    // Auxiliares de Hoja (Opcion Q)
    void hojasRecursivo(pnodoAbb nodo);
};

#endif // ARBOL_HPP