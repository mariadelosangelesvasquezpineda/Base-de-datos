//Empleado.cpp
#include "Clase - Empleado.h"
#include <cstring>
#include <windows.h>
#include <limits>
#include "Define - colores.h"
using namespace std;
Empleado::Empleado(){
	salario = new int;
	cargo = new char[50];
    estado = new char[50];
}
Empleado::~Empleado(){
	delete[] salario;
	delete[] cargo;
    delete[] estado;
}  
void Empleado::setSalario(int nuevoSalario) {
	*salario = nuevoSalario;
}

int Empleado::getSalario()  {
	return *salario;
}

void Empleado::setCargo(const char* nuevoCargo) {
	strncpy(cargo, nuevoCargo, sizeof(cargo));
}

const char* Empleado::getCargo()  {
	return cargo;
}

void Empleado::setEstado(const char* nuevoEstado) {
	strncpy(estado, nuevoEstado, sizeof(estado));
}

const char* Empleado::getEstado(){
	return estado;
}

