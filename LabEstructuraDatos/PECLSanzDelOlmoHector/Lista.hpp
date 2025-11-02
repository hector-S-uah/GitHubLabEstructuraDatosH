#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
class Lista
{
public:
	Lista();
	~Lista();
	void insertar(Aficionado* aficionado);
	void buscar();//muestra primer aficionado en acceder(primero en lista), ultimo socio en acceder, primer simpatizante en acceder, y ultimo aficionado en acceder al estadio(ultimo de la lista)
	int getLongitudLista();
	void vaciarLista();
	
private:
	int longitud;
	pnodoLista primero, ultimo;
};

#endif // LISTA_HPP
