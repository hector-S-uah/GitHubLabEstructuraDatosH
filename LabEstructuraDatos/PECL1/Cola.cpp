#include "Cola.hpp"

Cola::Cola()
{
	primeroCola=NULL;
	ultimoCola=NULL;
	longitud=0;
}
void Cola::insertar(Aficionado* aficionado){
	pnodoCola nuevo;
	nuevo=new NodoCola(aficionado, NULL);	//se pone null ya que los nodos en las colas SIEMPRE apuntan a null
	if(ultimoCola)
		ultimoCola->siguiente=nuevo;
	ultimoCola=nuevo;
	if(!primeroCola)
		primeroCola=nuevo;
	longitud++;
}
void Cola::mostrar(){
	pnodoCola aux=primeroCola;
	if (!aux){
		cout<<"\t La cola esta vacia"<<endl;
		return;
	}		
	cout<<"\t El contenido de la cola es:"<<endl;
	while(aux){
		aux->aficionado->mostrar();
		aux=aux->siguiente;
	}
	cout<<endl;
}
Aficionado*Cola::extraer(){
	pnodoCola nodo;
	Aficionado*aficionado;
	
	if (!primeroCola){
		return NULL;
	}
	
	nodo=primeroCola;
	primeroCola=primeroCola->siguiente;
	aficionado=nodo->aficionado;
	delete nodo;
	longitud--;
	return aficionado;	
}
int Cola::getLongitud(){
	return this->longitud;
}
bool Cola::esVacia(){
	return (primeroCola==NULL);
}
void Cola::vaciarCola(){
	pnodoCola aux;
	while(primeroCola){
		aux=primeroCola;
		primeroCola=primeroCola->siguiente;
		delete aux->aficionado;
		delete aux;
	}
	longitud=0;
}
Cola::~Cola()
{
	while(primeroCola){
		extraer();
	}
}

