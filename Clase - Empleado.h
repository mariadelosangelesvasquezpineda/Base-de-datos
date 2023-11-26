//Empleado.h
#pragma once
#include "Clase - Persona.h"

class Empleado: public Persona{
protected:
    int *salario;
    char *cargo;
    char *estado;
public:
	Empleado();
	~Empleado();
	void setSalario(int nuevoSalario);
    void setCargo(const char* nuevoCargo);
    void setEstado(const char* nuevoEstado);
    int getSalario();
    const char* getCargo();
    const char* getEstado();
};