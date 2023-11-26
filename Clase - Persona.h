//Persona.h
#pragma once
#include <iostream>
class Persona {

public:
	char *nombreUsuario;
	char *contrasena;
    char *nombre; 
    char *apellido; 
    int  *edad;
	char *dni; 
    char *celular;
    char *correo; 
    char *genero;	//mover a productos
    char *direccion; //sacar

	Persona();
	~Persona();
	void ignoreLine();

	int Longitud(char *dato,char caracter);
	void ingresar_nombre(FILE *doc);
	void ingresar_apellido(FILE *doc);
	void ingresar_DNI(FILE *doc);
	void ingresar_Edad(FILE *doc);
	void ingresar_Celular(FILE *doc);
	void ingresar_Correo(FILE *doc);
	void ingresar_Genero(FILE *doc);
	void ingresar_Direccion(FILE *doc);
	void ingresarNombreUsuario(FILE *doc);
	void ingresarContrasena(FILE *doc);
	bool autenticar(const char* nombreUsuarioInput, const char* contrasenaInput);
	void ingresarInformacion(FILE* doc);
	void mostrarInformacion();
};
