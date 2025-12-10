#include "Lista.hpp"

Lista::Lista()
{
	primero=NULL;
	ultimo=NULL;
	longitud=0;
}
Aficionado* Lista::extraerPrimero() {
    if (primero == NULL) {
        return NULL;
    }
    
    pnodoLista nodo = primero;
    Aficionado* aficionadoExtraido = nodo->aficionado;
    
    primero = primero->siguiente;
    if (primero) {
        primero->anterior = NULL;
    } else {
        // La lista quedó vacía
        ultimo = NULL;
    }
    
    // NO borramos el aficionado, solo el nodo (la caja), 
    // porque el aficionado se lo lleva el árbol.
    delete nodo; 
    longitud--;
    return aficionadoExtraido;
}
void Lista::insertar(Aficionado* aficionado){
	pnodoLista nuevo = new NodoLista(aficionado);
	longitud++;

	
	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
		return;
	}

	
	//Buscar el punto de inserción
	
	bool esNuevoSocio = aficionado->esSocio();
	int nuevaHora = aficionado->getHoraLlegada();
	pnodoLista aux = primero;

	while (aux != NULL) {
		bool esAuxSocio = aux->aficionado->esSocio();
		int auxHora = aux->aficionado->getHoraLlegada();

		if (esNuevoSocio) { 
			//Estamos insertando un socio
			if (!esAuxSocio) {
				// 'aux' es el primer simpatizante. El nuevo socio va justo antes.
				break; 
			}
			if (nuevaHora < auxHora) {
				// 'aux' es un socio con hora posterior. Insertar antes.
				break;
			}
		} else {
			// --- Estamos insertando un SIMPATIZANTE ---
			if (esAuxSocio) {
				// 'aux' es un socio. Los simpatizantes van después. Continuar.
			} else {
				// 'aux' también es simpatizante. Comprobar hora.
				if (nuevaHora < auxHora) {
					// Insertar en orden de hora.
					break;
				}
			}
		}
		aux = aux->siguiente;
	}

	if (aux == NULL) {
		// Insertar al final de la lista
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;
		ultimo = nuevo;
	} else if (aux == primero) {
		// Insertar al principio de la lista
		primero->anterior = nuevo;
		nuevo->siguiente = primero;
		primero = nuevo;
	} else {
		// Insertar en medio (antes de 'aux')
		nuevo->anterior = aux->anterior;
		nuevo->siguiente = aux;
		aux->anterior->siguiente = nuevo;
		aux->anterior = nuevo;
	}
}

void Lista::buscar(){
	if (primero==NULL){
		return;
	}
	else{
		cout<<"el primer aficionado en entrar es: "<<endl;
		primero->aficionado->mostrar();
		pnodoLista aux=ultimo;
		pnodoLista ultimoSocio=NULL;
		while (aux!=NULL){
			if (aux->aficionado->esSocio()){
				ultimoSocio=aux;
				break;
			}
			aux=aux->anterior;
		}
		cout<<endl<<"El ultimo socio en entrar fue: "<<endl;
		ultimoSocio->aficionado->mostrar();
		aux=primero;
		pnodoLista primerSimpatizante=NULL;
		while (aux!=NULL){
			if(!aux->aficionado->esSocio()){
				primerSimpatizante=aux;
				break;
			}
			aux=aux->siguiente;
		}
		cout<<endl<<"el primer simpatizante que entra es: "<<endl;
		primerSimpatizante->aficionado->mostrar();
		cout<<endl<<"el ultimo aficionado en entrar ha sido: "<<endl;
		ultimo->aficionado->mostrar();
	}
}
int Lista::getLongitudLista(){
	return this->longitud;
}
void Lista::vaciarLista(){
	pnodoLista aux;
	while (primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux->aficionado;
		delete aux;
	}
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

Lista::~Lista()
{
	pnodoLista aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux->aficionado;
        delete aux;
    }
}

