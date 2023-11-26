//Lista_Empleados.cpp
#include "Lista_Empleados.h"
#include "Clase - Empleado.h"
#include <cstring>

bool Lista_Empleados::buscar_inicial(Administrador* empleados[],int cantidad_Empleados, char inicial_buscada){	
	bool empleado_existente=false;
	for (int i=0; i<cantidad_Empleados;i++)
	{
		if(toupper(empleados[i]->nombre[0]) == toupper(inicial_buscada))
		{
			empleados[i]->mostrarInformacion();
			empleado_existente = true;
		}
	}
	return empleado_existente;
}

bool Lista_Empleados::buscar_nombre(Administrador* empleados[],int cantidad_Empleados, char* nombre_buscado){
	bool empleado_existente=false;
	for (int i=0; i<cantidad_Empleados;i++)
	{
		if(strcmpi(empleados[i]->nombre, nombre_buscado) == 0)
		{
			empleados[i]->mostrarInformacion();
			empleado_existente = true;
		}
	}
	return empleado_existente;
}

bool Lista_Empleados::buscar_apellido(Administrador* empleados[],int cantidad_Empleados, char* apellido_buscado){
	bool empleado_existente=false;
	for (int i=0; i<cantidad_Empleados;i++)
	{
		if(strcmpi(empleados[i]->apellido, apellido_buscado) == 0)
		{
			empleados[i]->mostrarInformacion();
			empleado_existente = true;
		}
	}
	return empleado_existente;
}

bool Lista_Empleados::buscar_dni(Administrador* empleados[],int cantidad_Empleados, char* dni_buscado){
	bool empleado_existente=false;
	for (int i=0; i<cantidad_Empleados;i++)
	{
		if(strcmpi(empleados[i]->dni, dni_buscado) == 0)
		{
			empleados[i]->mostrarInformacion();
			empleado_existente = true;
		}
	}
	return empleado_existente;
}

bool Lista_Empleados::buscar_genero(Administrador* empleados[],int cantidad_Empleados, char genero_buscado){
	bool empleado_existente=false;
	for (int i=0; i<cantidad_Empleados;i++)
	{
		if(toupper(empleados[i]->genero[0]) == toupper(genero_buscado))
		{
			empleados[i]->mostrarInformacion();
			empleado_existente = true;
		}
	}
	return empleado_existente;
}