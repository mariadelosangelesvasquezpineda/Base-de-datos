//Pedidos.cpp
#include "Pedidos.h"
#include "Clase - Productos.h"
#include <iostream>
using namespace std;
Pedidos::Pedidos() {
	nombre = new char[50]; 
	fecha_pedido = new char[50];
	monto_total = new double; 
	cantidad = new int;
	//precio_unit= new double;

} 
Pedidos::~Pedidos() {
	delete[] nombre;
	delete[] fecha_pedido;
	delete monto_total;
	delete cantidad;
	delete precio_unit;
} 

void Pedidos::ingresar_pedido(FILE *doc){
	cout<<"Nombre: ";
	cin.getline(nombre, 50);
	fprintf(doc, "\nNombre: %s\n",nombre);
	//Fecha
	cout<<"Fecha del pedido: ";
	cin.getline(fecha_pedido, 50);
	fprintf(doc, "Fecha del pedido: %s\n", fecha_pedido);
	//Monto
	cout<<"Fecha del pedido: ";
	cin.getline(fecha_pedido, 50);
	fprintf(doc, "Monto total: %s\n", monto_total);
	//Cantidad
	cout<<"Fecha del pedido: ";
	cin.getline(fecha_pedido, 50);
	fprintf(doc, "Cantidad: %s\n", cantidad);
	
	
}
