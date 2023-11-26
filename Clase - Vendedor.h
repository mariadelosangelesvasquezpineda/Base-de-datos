//Vendedor.h
#pragma once
#include "Clase - Empleado.h"

class Vendedor: public Empleado{
public:
	bool iniciarSesionVendedor(const char* nombreUsuario, const char* contrasena);
};