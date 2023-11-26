//Cliente.h
#pragma once
#include "Clase - Persona.h"
#include <iostream>
#include <limits>
class Cliente : public Persona {
public:

	void mostrarClientes(Cliente* clientes[], int cantidad_Clientes);
	void clienteModificar(FILE* doc);
	bool iniciarSesionCliente(const char* nombreUsuario, const char* contrasena);
	void eliminarCliente(Cliente* clientes[], int& cantidad_Clientes);
};