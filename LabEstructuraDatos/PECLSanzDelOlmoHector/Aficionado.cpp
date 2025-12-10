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
	string estado=" Simpatizante ";
	if(socio){
		estado=" Socio ";
	}
	cout <<"\t"<< "ID: "<<setw(2)<<setfill('0')<<ID<<" Hora: 18:"<<setw(2)<<setfill('0')<<hora<<", "<<"Tipo: "<<estado<< endl;
}
Aficionado::~Aficionado() {}
