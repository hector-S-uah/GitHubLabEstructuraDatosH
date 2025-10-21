#include "Gestor.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Gestor gestor;
	char opcion;

	do {

		cout << "\n\t--------------------------------------------------------------"
				"--------\n";
		cout << "\tAficionados en la pila -> " <<gestor.AficionadosEnPila()
			 << "\n\tAficionados en las colas:\n \t\tSocios-> " <<gestor.SociosEnCola()<< "\tSimpatizantes-> "
			 <<gestor.SimpatizantesEnCola()
			 << " \n\tAficionados en la lista -> " << 0 /*gestor.AficionadosEnLista()*/
			 << "\n\tAficionados en el arbol -> " << 0							  /*gestor.AficionadosEnArbol()*/
			 << "\n";
		cout << "\t----------------------------------------------------------------"
				"------\n\n";

		cout << "\tA. Generar 10 Aficionados de forma aleatoria y almacenarlos en la "
				"Pila.\n";
		cout << "\tB. Consultar todos los Aficionados generados en la Pila.\n";
		cout << "\tC. Borrar los Aficionados generados en la pila.\n";
		cout << "\tD. Simular llegada de los Aficionados en las colas.\n";
		cout << "\tE. Consultar los Aficionados en las cola de socios.\n";
		cout << "\tF. Consultar los Aficionados en la cola de simpatizantes.\n";
		cout << "\tG. Borrar todos los Aficionados de las colas.\n";
		cout << "\tH. Simular la entrada de los Aficionados a la lista.\n";
		cout << "\tI. Buscar en la lista el primer Aficionado, "
				"el ultimo socio, el primer simpatizante y "
				"el ultimo Aficionado que acceden al estadio.\n";
		cout << "\tJ. Reiniciar el programa.\n";
		cout << "\tK. Crear y dibujar el ABB en consola.\n";
		cout << "\tL. Mostrar los datos de todos los socios ordenados "
				"por sus IDs de menor a mayor.\n";
		cout << "\tM. Mostrar los datos de todos los simpatizantes ordenados "
				"por sus IDs de menor a mayor.\n";
		cout << "\tN. Mostrar los datos de todos los Aficionados recorriendo el arbol "
				"en inorden.\n";
		cout << "\tO. Buscar en el ABB el primer Aficionado, "
				"el ultimo socio, el primer simpatizante y "
				"el ultimo Aficionado que acceden al estadio.\n";
		cout << "\tP. Mostrar el numero de aficionados en el ABB cuyos ID's son pares.\n";
		cout << "\tQ. Mostrar los aficionados que se encuentran almacenados en un nodo hoja.\n";
		cout << "\tR. Eliminar un aficionado indicado por su ID. Mostrar el arbol antes y despues tras la eliminacion de dicho aficionado.\n";
		cout << "\tS. Salir.\n\n";

		cout << "\tIndique la opcion deseada: ";
		cin >> opcion;
		opcion = toupper(opcion);
		// system("clear");
		system("cls");

		switch(opcion) {

		case 'A':
			gestor.genera10Aficionados();
			break;
		case 'B':
			gestor.muestraAficionados();
			break;
		case 'C':
			gestor.borraAficionadosPila();
			break;
		case 'D':
			gestor.encolarAficionados();
			break;
		case 'E':
			gestor.muestraSociosCola();
			break;
		case 'F':
			gestor.muestraSimpatizantesCola();
			break;
		case 'G':
			gestor.borraAficionadosColas();
			break;
		case 'H':
			// gestor.enlistarAficionados();
			break;
		case 'I':
			// gestor.buscarAficionados();
			break;
		case 'J':
			// gestor.reiniciar();
			break;
		case 'K':
			//...;
			break;
		case 'L':
			//...;
			break;
		case 'M':
			//...;
			break;
		case 'N':
			//...;
			break;
		case 'O':
			//...;
			break;
		case 'P':
			//...;
			break;
		case 'Q':
			//...;
			break;
		case 'R':
			//...;
			break;
		case 'S':
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion incorrecta!\n\n";
			break;
		}
	} while(opcion != 'S');

	return 0;
}