//Pedidos.h
#pragma once
#include<iostream>

class Pedidos {
	
private:
	char *nombre;
	char *fecha_pedido;
	double *monto_total;
	int *cantidad;
	double *precio_unit;
	
public: 
	Pedidos();
	~Pedidos();
	void ingresar_pedido(FILE *doc);

};