#include "Arbol.hpp"


// =================================================================
// ESTRUCTURA BÁSICA Y DE GESTIÓN
// =================================================================

Arbol::Arbol()
{
	raiz = nullptr;
	contador = 0;
}

// Auxiliar para liberar toda la memoria del árbol
void Arbol::liberarNodos(pnodoAbb nodo){
	if (nodo==nullptr){
		return;
	}
	liberarNodos(nodo->izq);
	liberarNodos(nodo->der);
	delete nodo->aficionado;
	delete nodo;
}

void Arbol::vaciarArbol(){
	liberarNodos(raiz);
	raiz=nullptr;
	contador=0;
}

int Arbol::getContador(){
	return contador;
}

bool Arbol::esVacio(){
	return raiz==nullptr;
}

Arbol::~Arbol()
{
	vaciarArbol();
}

// =================================================================
// INSERCIÓN
// =================================================================

void Arbol::insertarRaizFicticia(Aficionado* ficticio){
	if(raiz){
		delete ficticio;
		return;
	}
	// La raíz ficticia (ID 0) no cuenta para el contador real.
	raiz= new NodoArbol(ficticio);
}

// Auxiliar: Inserción estándar de ABB para subárboles
void Arbol::insertarRecursivo(pnodoAbb& nodo, Aficionado* aficionado){
	if (nodo==nullptr){
		nodo=new NodoArbol(aficionado);
		contador++; // <-- Se incrementa el contador al insertar un aficionado real
		return;
	}
	// Se ordena según el ID del aficionado
	if(aficionado->getID()<nodo->aficionado->getID()){
		insertarRecursivo(nodo->izq, aficionado);
	}else if (aficionado->getID()>nodo->aficionado->getID()){
		insertarRecursivo(nodo->der, aficionado);
	}
}

void Arbol::insertarAficionado(Aficionado*aficionado){
	if (raiz==nullptr){
		cout<<"\tError: Raiz ficticia no creada"<<endl;
		return;
	}
	// Socios van al subárbol izquierdo de la raíz ficticia.
	if (aficionado->esSocio()){
		insertarRecursivo(raiz->izq, aficionado);
	}
	// Simpatizantes van al subárbol derecho de la raíz ficticia.
	else{
		insertarRecursivo(raiz->der, aficionado);
	}
}

// =================================================================
// DIBUJO
// =================================================================

// Auxiliar: Calcula la altura del árbol
int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der)); 
}

// Auxiliar: Construye recursivamente las líneas de salida
void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p, char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";
    
    // Ajustar el desplazamiento si es necesario
    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    // 1. DIBUJAR HIJO IZQUIERDO
    if(nodo->izq) {
        int ID_izq = nodo->izq->aficionado->getID();
        string izqdato = SP + to_string(ID_izq) + SP;
        
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    // 2. IMPRIMIR EL NODO ACTUAL
    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');

    int ID_actual = nodo->aficionado->getID();
	
    string nododato;
    
    if (ID_actual == 0) {
        nododato = " " + to_string(ID_actual) + " (Ficticia) ";
    } else {
        nododato = SP + to_string(ID_actual)+ SP;
    }
    
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    // 3. DIBUJAR HIJO DERECHO
    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar()
{
    if (raiz == nullptr) {
        cout << "\tArbol de busqueda vacio" << endl;
        return;
    }

    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' '); 

    // Fase de post-procesamiento para dibujar las ramas horizontales
    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                // Asegurar que el nivel del padre (i-1) sea lo suficientemente largo
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                
                int jj = j;
                if(linkAbove[i][j] == 'L') { 
                    // Rama izquierda: conecta el hijo (j) con el padre (jj). La rama va hacia la derecha del padre.
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    // Dibuja la rama horizontal ('_')
                    for(int k = j + 1; k < jj - 1; k++) 
                        output[i - 1][k] = '_';
                    
                } else if(linkAbove[i][j] == 'R') { 
                    // Rama derecha: conecta el hijo (j) con el padre (jj). La rama va hacia la izquierda del padre.
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    // Dibuja la rama horizontal ('_')
                    for(int k = j - 1; k > jj + 1; k--) 
                        output[i - 1][k] = '_';
                }
                
                // Finalmente, coloca la línea vertical ('|')
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << "\n\t--- Estructura del Arbol de Aficionados (IDs) ---\n\n";
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << "\n\n";
}

// =================================================================
// RECORRIDOS (Inorden)
// =================================================================

// Auxiliar: Recorrido Inorden con filtrado
void Arbol::inorden(pnodoAbb nodo, bool soloSocios, bool soloSimpatizantes){
    if (nodo == nullptr) {
        return;
    }
    
    // 1. Recorrer Subárbol Izquierdo
    inorden(nodo->izq, soloSocios, soloSimpatizantes);
    
    // 2. Procesar Nodo Actual
    if (nodo != raiz) { 
        bool esSocio = nodo->aficionado->esSocio();
        
        // Filtro lógico
        if ((soloSocios && esSocio) || (soloSimpatizantes && !esSocio)) {
            nodo->aficionado->mostrar();
        }
    }
    
    // 3. Recorrer Subárbol Derecho
    inorden(nodo->der, soloSocios, soloSimpatizantes);
}

// Opción L: Mostrar Socios ordenados por ID (Inorden)
void Arbol::mostrarSociosInorden(){
    if (raiz == nullptr || raiz->izq == nullptr) {
        cout << "\tNo hay socios en el arbol." << endl;
        return;
    }
    // Recorrer solo el subárbol IZQUIERDO (Socios)
    inorden(raiz->izq, true, false); 
}

// Opción M: Mostrar Simpatizantes ordenados por ID (Inorden)
void Arbol::mostrarSimpatizantesInorden(){
    if (raiz == nullptr || raiz->der == nullptr) {
        cout << "\tNo hay simpatizantes en el arbol." << endl;
        return;
    }
    // Recorrer solo el subárbol DERECHO (Simpatizantes)
    inorden(raiz->der, false, true); 
}

// Opción N: Mostrar todos los aficionados (Inorden Completo)
void Arbol::mostrarCompletoInorden(){
     if (raiz == nullptr || (raiz->izq == nullptr && raiz->der == nullptr)) {
        cout << "\tArbol de aficionados vacio." << endl;
        return;
    }
    // Recorrer todo el árbol, sin filtros de tipo.
    inorden(raiz, true, true); 
}

// =================================================================
// ELIMINACIÓN (Opción R)
// =================================================================

// Auxiliar: Devuelve el puntero al nodo con el valor mínimo (sucesor inorden)
pnodoAbb Arbol::buscarSucesor(pnodoAbb nodo) {
	pnodoAbb actual = nodo;
	while (actual && actual->izq != nullptr) {
		actual = actual->izq;
	}
	return actual;
}
//opcion o
// Auxiliar: Encuentra los aficionados con horas extremas (Unifica las 4 búsquedas)
void Arbol::buscarExtremosRecursivo(pnodoAbb nodo, Aficionado*& primerAficionado, Aficionado*& ultimoSocio, Aficionado*& primerSimpatizante, Aficionado*& ultimoAficionado) {
    if (nodo == nullptr) {
        return;
    }
    
    buscarExtremosRecursivo(nodo->izq, primerAficionado, ultimoSocio, primerSimpatizante, ultimoAficionado);
    
    // Procesar nodo actual
    Aficionado* actual = nodo->aficionado;
    if (actual->getID()!=0){
		// 1. Primer Aficionado (Hora Mínima global)
		if (primerAficionado == nullptr || actual->getHoraLlegada() < primerAficionado->getHoraLlegada()) {
			primerAficionado = actual;
		}
		
		// 4. Último Aficionado (Hora Máxima global)
		if (ultimoAficionado == nullptr || actual->getHoraLlegada() > ultimoAficionado->getHoraLlegada()) {
			ultimoAficionado = actual;
		}
		
		if (actual->esSocio()) {
			// 2. Último Socio (Hora Máxima Socio)
			if (ultimoSocio == nullptr || actual->getHoraLlegada() > ultimoSocio->getHoraLlegada()) {
				ultimoSocio = actual;
			}
		} else {
			// 3. Primer Simpatizante (Hora Mínima Simpatizante)
			if (primerSimpatizante == nullptr || actual->getHoraLlegada() < primerSimpatizante->getHoraLlegada()) {
				primerSimpatizante = actual;
			}
		}
}
    buscarExtremosRecursivo(nodo->der, primerAficionado, ultimoSocio, primerSimpatizante, ultimoAficionado);
}

void Arbol::buscarAficionados() {
    if (raiz == nullptr || (raiz->izq == nullptr && raiz->der == nullptr)) {
        cout << "\tEl arbol esta vacio." << endl;
        return;
    }
    Aficionado* primer = nullptr;
    Aficionado* ultimoSocio = nullptr;
    Aficionado* primerSimpa = nullptr;
    Aficionado* ultimo = nullptr;
    
    buscarExtremosRecursivo(raiz, primer, ultimoSocio, primerSimpa, ultimo);
        
    cout << "\n\t--- Busqueda de Extremos en el ABB (por hora de llegada) ---" << endl; // AÑADIDO ENCABEZADO
    cout << "\t1. Primer Aficionado en entrar:" << endl;
    if (primer) primer->mostrar(); else cout << "\t\tNo se encontraron aficionados." << endl;
    
    cout << "\t2. Ultimo Socio en entrar:" << endl;
    if (ultimoSocio) ultimoSocio->mostrar(); else cout << "\t\tNo se encontraron socios." << endl;
    
    cout << "\t3. Primer Simpatizante en entrar:" << endl;
    if (primerSimpa) primerSimpa->mostrar(); else cout << "\t\tNo se encontraron simpatizantes." << endl;
    
    cout << "\t4. Ultimo Aficionado en entrar:" << endl;
    if (ultimo) ultimo->mostrar(); else cout << "\t\tNo se encontraron aficionados." << endl;
    cout << "\t------------------------------------------------------------------" << endl; // AÑADIDO PIE
    
}

//opcion p
// Auxiliar: Cuenta recursivamente los IDs pares
void Arbol::contarParesRecursivo(pnodoAbb nodo, int& contadorPares) {
    if (nodo == nullptr) {
        return;
    }
    
    // 1. Procesar Nodo (Preorden)
    if (nodo->aficionado->getID() % 2 == 0 && nodo->aficionado->getID()!=0) {
        contadorPares++;
    }
    
    contarParesRecursivo(nodo->izq, contadorPares);
    contarParesRecursivo(nodo->der, contadorPares);
}

void Arbol::contarIDsPares() {
    if (raiz == nullptr || (raiz->izq == nullptr && raiz->der == nullptr)) {
        cout << "\tEl arbol esta vacio." << endl;
        return;
    }
    int contadorPares = 0;
    contarParesRecursivo(raiz, contadorPares);
    
    cout << "\tHay " << contadorPares <<" aficionados con ID par en el arbol"<< endl;
}
//q
// Auxiliar: Muestra los aficionados en nodos hoja (sin hijos)
void Arbol::hojasRecursivo(pnodoAbb nodo) {
    if (nodo == nullptr) {
        return;
    }
    
    // Condición de hoja: No tiene hijo izquierdo Y no tiene hijo derecho
    if (nodo->izq == nullptr && nodo->der == nullptr) {
        nodo->aficionado->mostrar();
        return;
    }
    
    hojasRecursivo(nodo->izq);
    hojasRecursivo(nodo->der);
}


void Arbol::mostrarAficionadosHoja() {
    if (raiz == nullptr || (raiz->izq == nullptr && raiz->der == nullptr)) {
        cout << "\tEl arbol esta vacio o solo contiene la raiz ficticia." << endl;
        return;
    }
    hojasRecursivo(raiz);

}
//opcion r
// Auxiliar: Elimina un nodo recursivamente
void Arbol::eliminarRecursivo(pnodoAbb& nodo, int ID) {
	if (nodo == nullptr) {
		cout << "\tAficionado con ID " << ID << " no encontrado." << endl;
		return;
	}

	// 1. Búsqueda
	if (ID < nodo->aficionado->getID()) {
		eliminarRecursivo(nodo->izq, ID);
	} else if (ID > nodo->aficionado->getID()) {
		eliminarRecursivo(nodo->der, ID);
	} else {
		// 2. Nodo Encontrado
		pnodoAbb nodoAEliminar = nodo;

		// Caso 1: Cero o un hijo
		if (nodo->izq == nullptr) {
			nodo = nodo->der; 
		} else if (nodo->der == nullptr) {
			nodo = nodo->izq;
		} 
		// Caso 2: Dos hijos
		else {
			pnodoAbb sucesor = buscarSucesor(nodo->der);

			// Copiar los datos del sucesor al nodo actual y liberar el aficionado anterior
			delete nodo->aficionado; 
			nodo->aficionado = sucesor->aficionado;
			
			// ELIMINAR EL SUCESOR del subárbol derecho (la copia ha sido completada)
			eliminarRecursivo(nodo->der, sucesor->aficionado->getID());
			return; // Salir, la recursión inferior manejó la reducción del contador
		}

		// Finalizar la eliminación (Casos 0 y 1 hijo)
		if (nodoAEliminar != nullptr) {
			delete nodoAEliminar->aficionado;
			delete nodoAEliminar;
			contador--;
			cout << "\tAficionado con ID " << ID << " eliminado exitosamente." << endl;
		}
	}
}

// Método Público de Eliminación
void Arbol::eliminarAficionadoPorID(int ID){
	if (raiz == nullptr || (raiz->izq == nullptr && raiz->der == nullptr)) {
		cout << "\tError: El arbol esta vacio (solo tiene la raiz ficticia o esta completamente vacio)" << endl;
		return;
	}
	
	// Dirigirse al subárbol correcto según si es Socio (Par) o Simpatizante (Impar)
	if (ID % 2 == 0) {
		eliminarRecursivo(raiz->izq, ID);
	} 
	else {
		eliminarRecursivo(raiz->der, ID);
	}
}

