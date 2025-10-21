#include "Gestor.hpp"

Gestor::Gestor()
{
	srand(time(NULL));	//inicializamos la semilla de numeros aleatorios para que no salgan siempre los mismos minutos cada vez que generamos 10 aficionados
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
	cout<<"\tLos aficionados ya han sido creados"<<endl;
}
void Gestor::muestraAficionados(){
		pilaAficionados.mostrar();
}
void Gestor::borraAficionadosPila(){
	cout<<"\tEliminando aficionados de la pila ..."<<endl;
	pilaAficionados.vaciarPila();
	cout<<"\t Se eliminaron todos los aficionados de la lista exitosamente"<<endl;
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
	cout<<"\t Todos los aficionados se han ido a sus respectivas colas"<<endl;
}
void Gestor::borraAficionadosColas(){
	if (colaSocios.esVacia()^colaSimpatizantes.esVacia()){
		cout<<"\t Las colas ya estan vacias"<<endl;
		return;
	}
	colaSocios.vaciarCola();
	colaSimpatizantes.vaciarCola();
	cout<<"\t Los aficionados de las colas han sido eliminados exitosamente"<<endl;
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
Gestor::~Gestor()
{
}

