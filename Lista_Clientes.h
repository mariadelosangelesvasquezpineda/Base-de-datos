//Lista_Clientes.h
#pragma once
#include "Clase - Cliente.h"
class Lista_Clientes {
public: 
	bool buscar_inicial(Cliente* clientes[],int cantidad_Clientes, char inicial_buscada);
	bool buscar_nombre(Cliente* clientes[],int cantidad_Clientes, char* nombre_buscado);
	bool buscar_apellido(Cliente* clientes[],int cantidad_Clientes, char* apellido_buscado);
	bool buscar_dni(Cliente* clientes[],int cantidad_Clientes, char* dni_buscado);
	bool buscar_genero(Cliente* clientes[],int cantidad_Clientes, char genero_buscado);
	
};