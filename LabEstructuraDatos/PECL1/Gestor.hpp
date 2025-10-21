#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include <ctime>	//por lo mismo que hemos puesto el include en el cpp de aficionado
#include <algorithm>

class Gestor
{
public:
	Gestor();
	~Gestor();
	
	void genera10Aficionados();	//hecho
	void muestraAficionados();	//hecho
	void borraAficionadosPila();//hecho
	void encolarAficionados();
	void muestraSociosCola();
	void muestraSimpatizantesCola();
	void borraAficionadosColas();
	void enlistarAficionados();
	void buscarAficionados();
	void reiniciar();
	int AficionadosEnPila();	//hecho
	int SociosEnCola();
	int SimpatizantesEnCola();

private:
	Pila pilaAficionados;
	int ronda;
	Cola colaSocios;
	Cola colaSimpatizantes;

};

#endif // GESTOR_HPP
