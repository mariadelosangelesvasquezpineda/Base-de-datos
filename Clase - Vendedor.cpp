//Vendedor.cpp
#include "Clase - Vendedor.h"
#include <cstring>
#include <windows.h>
#include <limits>
#include "Define - colores.h"
using namespace std;
bool Vendedor::iniciarSesionVendedor(const char* nombreUsuario, const char* contrasena) {
	return autenticar(nombreUsuario, contrasena);
}