#include "Aficionado.hpp"

Aficionado::Aficionado(int ID)
{
    this->ID = ID;
    this->hora = rand() % 60;	//genera un numero aleatorio entre 0 y 59
    this->socio = (ID % 2 == 0);	//si es par es socio
}
int Aficionado::getID() { 
	return this->ID;
}
int Aficionado::getHoraLlegada() { 
	return this->hora; 
}
bool Aficionado:: esSocio(){
	return this->socio;
}
void Aficionado::mostrar(){
	string estado=" no es socio ";
	if(socio){
		estado=" es socio ";
	}
	cout <<"\t"<< setw(10)<< "El anfitrion con ID: "<<ID<<" entro a las 18:"<<setw(2)<<setfill('0')<<hora<<", "<<estado<< endl;
}
Aficionado::~Aficionado() {}
