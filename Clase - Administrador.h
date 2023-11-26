//Empleado.h
#pragma once
#include "Clase - Empleado.h"

class Administrador: public Empleado{
public:
	void ignoreLine();
    void ingresarEmpleado(FILE *doc);
    void mostrarempleado();
	void mostrarEmpleados(Administrador* empleados[], int cantidad_Empleados);
	void empleadoModificar(FILE* doc);
	void eliminarEmpleado(Administrador* empleados[], int& cantidadEmpleados);
	bool iniciarSesionAdministrador(const char* nombreUsuario, const char* contrasena);
};