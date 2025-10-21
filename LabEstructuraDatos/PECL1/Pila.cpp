#include "Pila.hpp"


Pila::Pila()
{
	ultimoPila=NULL;
	longitudPila=0;
}
void Pila::insertar(Aficionado*aficionado){
	pnodoPila nuevo;
	nuevo=new NodoPila(aficionado, ultimoPila);
	ultimoPila=nuevo;
	longitudPila++;
}
Aficionado*Pila::extraer(){
	pnodoPila nodo;
	Aficionado*aficionado;
	
	if(!ultimoPila)
		return NULL;
		
	nodo=ultimoPila;
	ultimoPila=nodo->siguiente;
	aficionado=nodo->aficionado;
	delete nodo;
	longitudPila--;
	return aficionado;
}
Aficionado*Pila::cima(){
	if(!ultimoPila)
		return NULL;
	return ultimoPila->aficionado;
}
void Pila::mostrar(){
	pnodoPila aux=ultimoPila;
	if (!aux){
		cout<<"\t La pila esta vacia"<<endl;
		return;
	}
	cout<<"\t El contenido de la pila es: "<<endl;
	while(aux){
		aux->aficionado->mostrar();	//Usa el metodo mostrar del aficionado
		aux=aux->siguiente;
	}
	cout<<endl;
}
void Pila::vaciarPila(){
	pnodoPila aux;
	while (ultimoPila){
		aux=ultimoPila;
		ultimoPila=ultimoPila->siguiente;
		delete aux->aficionado;
		delete aux;
	}
	longitudPila=0;
}
int Pila::getLongitud(){
	return this->longitudPila;
}
bool Pila::esVacia(){
	return (ultimoPila==NULL);
}

Pila::~Pila()
{
	pnodoPila aux;
	while(ultimoPila){
		aux=ultimoPila;
		ultimoPila=ultimoPila->siguiente;
		delete aux;
	}
}

