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
	abbAficionados.vaciarArbol();
}
int Gestor::AficionadosEnLista(){
	return listaOrdenada.getLongitudLista();
}
void Gestor::construirArbol(){
    if (listaOrdenada.getLongitudLista() == 0) {
        return;
    }
    abbAficionados.vaciarArbol();
    
    // 1. Crear la raíz ficticia...
    Aficionado* ficticio = new Aficionado(0);
    abbAficionados.insertarRaizFicticia(ficticio);
    
    Aficionado* aficionado;
    
    while((aficionado = listaOrdenada.extraerPrimero()) != NULL) {
        abbAficionados.insertarAficionado(aficionado);
    }
}
void Gestor::dibujarArbol(){
	abbAficionados.dibujar();
}
void Gestor::crearYDibujarArbol(){
	this->construirArbol();
	this->dibujarArbol();
}
int Gestor::AficionadosEnArbol(){
	return abbAficionados.getContador();
}
// Opción L: Mostrar los datos de todos los socios ordenados por sus IDs
void Gestor::mostrarSociosAbb(){
	abbAficionados.mostrarSociosInorden();
}

// Opción M: Mostrar los datos de todos los simpatizantes ordenados por sus IDs
void Gestor::mostrarSimpatizantesAbb(){
	abbAficionados.mostrarSimpatizantesInorden();
}

// Opción N: Mostrar los datos de todos los Aficionados recorriendo el arbol en inorden
void Gestor::mostrarAficionadosAbb(){
	abbAficionados.mostrarCompletoInorden();
}
// Opción O: Buscar extremos en el ABB (por hora de llegada)
void Gestor::buscarAbb(){
    abbAficionados.buscarAficionados();
}

// Opción P: Mostrar el numero de aficionados en el ABB cuyos ID's son pares
void Gestor::contarParesAbb(){
    abbAficionados.contarIDsPares();
}

// Opción Q: Mostrar los aficionados que se encuentran almacenados en un nodo hoja
void Gestor::mostrarHojasAbb(){
    abbAficionados.mostrarAficionadosHoja();
}
// Opción R: Eliminar un aficionado indicado por su ID (que se pide desde consola). Mostrar el árbol antes y después tras la eliminación de dicho aficionado. 
void Gestor::eliminarAficionado(int ID){
	abbAficionados.eliminarAficionadoPorID(ID);
}
Gestor::~Gestor()
{
}

