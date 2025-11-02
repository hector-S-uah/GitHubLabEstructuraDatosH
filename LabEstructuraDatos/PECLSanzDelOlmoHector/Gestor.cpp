#include "Gestor.hpp"

Gestor::Gestor()
{
	ronda=0;
}
void Gestor::genera10Aficionados(){
	cout<<"\t Creando 10 aficionados ..."<<endl;
	int n=10;
	int a[n];
	
	cout<<"\t Numeros de id ordenados:"<<endl;
	for (int i=0; i<n;i++){
		a[i]=(i+1)+(10*ronda);
		cout<<a[i]<<" ";
	}
	cout<<endl<<"\t Numero de id desordenado:"<<endl;
	random_shuffle(a, a+n);
	for (int i=0; i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;
	for (int i=0; i<n; i++){
		Aficionado*aficionado=new Aficionado(a[i]);
		pilaAficionados.insertar(aficionado);
	}
	ronda++;

}
void Gestor::muestraAficionados(){
		pilaAficionados.mostrar();
}
void Gestor::borraAficionadosPila(){
	pilaAficionados.vaciarPila();
	ronda=0;
}
int Gestor::AficionadosEnPila(){
	return pilaAficionados.getLongitud();
}
void Gestor::encolarAficionados(){
	while(!pilaAficionados.esVacia()){
		Aficionado* aficionado=pilaAficionados.extraer();
		if(aficionado->esSocio())
			colaSocios.insertar(aficionado);
		else
			colaSimpatizantes.insertar(aficionado);
	}
}
void Gestor::borraAficionadosColas(){
	colaSocios.vaciarCola();
	colaSimpatizantes.vaciarCola();
}
int Gestor::SociosEnCola(){
	return colaSocios.getLongitud();
}
int Gestor::SimpatizantesEnCola(){
	return colaSimpatizantes.getLongitud();
}
void Gestor::muestraSociosCola(){
	colaSocios.mostrar();
}
void Gestor::muestraSimpatizantesCola(){
	colaSimpatizantes.mostrar();
}
void Gestor::enlistarAficionados(){
	while (!colaSocios.esVacia()){
		Aficionado* aficionado=colaSocios.extraer();
		listaOrdenada.insertar(aficionado);
	}
	while (!colaSimpatizantes.esVacia()){
		Aficionado* aficionado= colaSimpatizantes.extraer();
		listaOrdenada.insertar(aficionado);
	}
}
void Gestor::buscarAficionados(){
	listaOrdenada.buscar();
}
void Gestor::reiniciar(){
	pilaAficionados.vaciarPila();
	ronda=0;
	colaSocios.vaciarCola();
	colaSimpatizantes.vaciarCola();
	listaOrdenada.vaciarLista();
}
int Gestor::AficionadosEnLista(){
	return listaOrdenada.getLongitudLista();
}
Gestor::~Gestor()
{
}

