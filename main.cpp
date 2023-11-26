#include "Clase - Empleado.h"
#include "Clase - Productos.h"
#include "Clase - Cliente.h"
#include "Pedidos.h"
#include "Carrito.h"
#include "Lista_Clientes.h"
#include "Lista_Empleados.h"
#include "Define - colores.h"
#include "Clase - Menu.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	FILE *doc_clientes=fopen("Clientes.txt","a+");	
	FILE *doc_empleados=fopen("Empleados.txt","a+");
	FILE *doc_productos=fopen("Productos.txt","a+");
	FILE *doc_pedidos=fopen("Pedidos.txt","a+");
    const int max_personas = 50; 
	const int max_productos = 50;
	const int max_pedidos = 50;	
	const int max_articulos = 30;	
	Cliente *clientes[max_personas];
    Administrador *empleados[max_personas];
	Productos *productos[max_productos];
	Pedidos *listapedidos[max_pedidos];
	Carrito *articulos[max_articulos];
    int cantidad_Clientes = 0;
    int cantidad_Empleados = 0;
	int cantidad_Productos = 0;
	int cantidad_articulos = 0; //por mientras
	int opcion;
	Menu menu;
	Cliente *cliente = new Cliente; 
    
	do{
		menu.menu_principal(opcion);
		switch (opcion){
			case 1:{
				menu.menuClientes(clientes, cantidad_Clientes, doc_clientes, productos, cantidad_Productos, doc_productos, opcion, cliente);
				break;
			}
			case 2:{
				menu.menuAdmin(clientes, cantidad_Clientes, empleados, cantidad_Empleados, productos, cantidad_Productos, doc_clientes, doc_empleados, doc_productos,opcion);
				break;
			}
			case 0:{
				cout << "\nHasta luego.\n";
				break;
			}
			default:
				cout <<RED<< "Opcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
				Sleep(700);
		}
    } while(opcion != 0);
	fclose(doc_clientes);
	fclose(doc_empleados);
	fclose(doc_productos);
	return 0;
}