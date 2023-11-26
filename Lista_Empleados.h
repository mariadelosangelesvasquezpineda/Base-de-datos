//Lista_Clientes.h
#pragma once
#include "Clase - Administrador.h"
class Lista_Empleados {
public: 
	bool buscar_inicial(Administrador* empleados[],int cantidad_Empleados, char inicial_buscada);
	bool buscar_nombre(Administrador* empleados[],int cantidad_Empleados, char* nombre_buscado);
	bool buscar_apellido(Administrador* empleados[],int cantidad_Empleados, char* apellido_buscado);
	bool buscar_dni(Administrador* empleados[],int cantidad_Empleados, char* dni_buscado);
	bool buscar_genero(Administrador* empleados[],int cantidad_Empleados, char genero_buscado);
	
};