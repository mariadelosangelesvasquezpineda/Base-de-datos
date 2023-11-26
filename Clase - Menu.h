//Menu.h
#pragma once
#include "Clase - Empleado.h"
#include "Clase - Administrador.h"
#include "Clase - Productos.h"
#include "Clase - Cliente.h"
#include "Lista_Clientes.h"
#include "Lista_Empleados.h"
#include "Define - colores.h"
#include <windows.h>
#include <iostream>
#include <limits>
class Menu{
public:
	void ignoreLine();
	
	int menu_principal(int &opcion);

	int menu_cliente(int &opcion);
	
	int menu_vendedor(int &opcion);
	
	int menu_admin(int &opcion);
	
	int menu_registro(int &opcion);
	
	int menu_mostrar(int &opcion);
	
	int menu_modificar(int &opcion);
	
	int menu_eliminar(int &opcion);
	
	int menu_buscar(int &opcion);

	int buscar_clientes(int &opcion);
	
	int buscar_vendedores(int &opcion);
	
	void menuClientes(Cliente *clientes[], int &cantidad_Clientes, FILE* doc_clientes,Productos *productos[], int &cantidad_Productos, FILE* doc_productos, int &opcion, Cliente *cliente);
	
	void menuAdmin(Cliente* clientes[], int &cantidad_Clientes, Administrador* empleados[], int &cantidad_Empleados, Productos* productos[], int &cantidad_Productos, FILE* doc_clientes, FILE* doc_empleados, FILE* doc_productos, int &opcion);
};