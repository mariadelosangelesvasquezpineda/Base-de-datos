//Lista_Clientes.cpp
#include "Lista_Clientes.h"
#include "Clase - Cliente.h"
#include <cstring>

bool Lista_Clientes::buscar_inicial(Cliente* clientes[],int cantidad_Clientes, char inicial_buscada){	
	bool cliente_existente=false;
	for (int i=0; i<cantidad_Clientes;i++)
	{
		if(toupper(clientes[i]->nombre[0]) == toupper(inicial_buscada))
		{
			clientes[i]->mostrarInformacion();
			cliente_existente = true;
		}
	}
	return cliente_existente;
}

bool Lista_Clientes::buscar_nombre(Cliente* clientes[],int cantidad_Clientes, char* nombre_buscado){
	bool cliente_existente=false;
	for (int i=0; i<cantidad_Clientes;i++)
	{
		if(strcmpi(clientes[i]->nombre, nombre_buscado) == 0)
		{
			clientes[i]->mostrarInformacion();
			cliente_existente = true;
		}
	}
	return cliente_existente;
}

bool Lista_Clientes::buscar_apellido(Cliente* clientes[],int cantidad_Clientes, char* apellido_buscado){
	bool cliente_existente=false;
	for (int i=0; i<cantidad_Clientes;i++)
	{
		if(strcmpi(clientes[i]->apellido, apellido_buscado) == 0)
		{
			clientes[i]->mostrarInformacion();
			cliente_existente = true;
		}
	}
	return cliente_existente;
}

bool Lista_Clientes::buscar_dni(Cliente* clientes[],int cantidad_Clientes, char* dni_buscado){
	bool cliente_existente=false;
	for (int i=0; i<cantidad_Clientes;i++)
	{
		if(strcmpi(clientes[i]->dni, dni_buscado) == 0)
		{
			clientes[i]->mostrarInformacion();
			cliente_existente = true;
		}
	}
	return cliente_existente;
}

bool Lista_Clientes::buscar_genero(Cliente* clientes[],int cantidad_Clientes, char genero_buscado){
	bool cliente_existente=false;
	for (int i=0; i<cantidad_Clientes;i++)
	{
		if(toupper(clientes[i]->genero[0]) == toupper(genero_buscado))
		{
			clientes[i]->mostrarInformacion();
			cliente_existente = true;
		}
	}
	return cliente_existente;
}