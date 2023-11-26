//Persona.cpp
#include "Clase - Persona.h"
#include <iostream>
#include <cstring>
#include <limits>
#include "Define - colores.h"
using namespace std;
Persona::Persona() {
		nombreUsuario = new char[50];
        contrasena = new char[50];
        nombre = new char[50];
        apellido = new char[50];
		edad = new int;
        dni = new char[9];
        celular = new char[50]; //sacarlo 
        correo = new char[50];
        genero = new char; //posibilidad de moverlo
        direccion = new char[50]; //sacarlo
}
Persona::~Persona() {
		delete[] nombreUsuario;
        delete[] contrasena;
        delete[] nombre;
        delete[] apellido;
        delete edad;
        delete[] dni;
		delete[] celular;
        delete[] correo;
        delete genero;
        delete[] direccion;
}

void Persona::ignoreLine(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Persona::Longitud(char *dato,char caracter){
	int longitud = 0;
	longitud = 0;
	while (dato[longitud] != caracter) {
			longitud++;
		}
	return longitud;
}


void Persona::ingresar_nombre(FILE *doc)
{
	do {
		cout << "\nNombre: ";
		cin.getline(nombre, 50);
			if (Longitud(nombre,'\0')<3) {  //Nombre: MIN 3 dígitos
				std::cout <<RED<< "\nEs muy corto.\n" <<RESET;
			}
			else if (Longitud(nombre,'\0')>20) {  //Nombre: MIN 3 dígitos
				std::cout <<RED<< "\nEs muy largo.\n" <<RESET;
			}
			else {
				fprintf(doc, "\nNombre: %s\n",nombre);
				break;
			}
	}while(true);
}

void Persona::ingresar_apellido(FILE *doc)
{
	do {
		cout << "\nApellido: ";
		cin.getline(apellido, 50);
		if (Longitud(apellido,'\0')<3) {  //Apellido: MIN 3 dígitos
			std::cout <<RED<< "\nEs muy corto.\n" <<RESET;
		}
		else if (Longitud(apellido,'\0')>20) {  //Apellido: MAX 20 dígitos
			std::cout <<RED<< "\nEs muy largo.\n" <<RESET;
		}
		else {
			fprintf(doc, "Apellido: %s\n",apellido);
			break;
		}
	} while (true);
}

void Persona::ingresar_DNI(FILE *doc)
{
	do {
		cout << "\nDNI: ";
		cin >> dni;
		if (Longitud(dni,'\0')==8) {  //DNI : max 8 dígitos
			fprintf(doc, "DNI: %s\n",dni);
			break;
		} 
		else {
			std::cout <<RED<< "\nEl DNI ingresado no cumple los requisitos.\n" <<RESET;
		}
	} while (true);
}

void Persona::ingresar_Edad(FILE *doc)
{
	do{
		cout << "\nEdad: ";
		if (cin >> *edad){
			if (*edad >= 18 && *edad<=110) {  //EDAD : 18 a 110 años
				fprintf(doc, "Edad: %d\n",*edad);
				break;
			} 
			else 
			{
			std::cout <<RED<< "\nLo siento, debes tener mas de 18 a"<<char(164)<<"os o no cumples los requisitos.\n" <<RESET;
			}
		}
		else
		{
			std::cout<<RED<< "\nPor favor, ingresa un n"<<char(163)<<"mero v"<<char(160)<<"lido.\n" <<RESET;
			std::cin.clear();
			ignoreLine();
		}
	}while(true);
}

void Persona::ingresar_Celular(FILE *doc)
{
	do{
		cout << "\nCelular: ";
		cin>>celular;
		if (Longitud(celular,'\0')==9 && celular[0]=='9') {  //Celular : max 9 dígitos
			fprintf(doc, "Celular: %s\n",celular);
			break;
		} else {
			std::cout <<RED<< "\nPor favor, ingresa un n"<<char(163)<<"mero de celular v"<<char(160)<<"lido.\n" <<RESET;
		}
	}while(true);
}	

void Persona::ingresar_Correo(FILE *doc)
{
	do{
		cout << GREEN<<"\nRequisitos para el correo:\n1.Tu nombre de usuario debe tener entre 6 y 30 caracteres\n2.Contener un '@'."<<RESET<<"\n\nCorreo: ";
		cin>>correo;
		if(Longitud(correo,'@')>=6 && Longitud(correo,'@')<=30){
			fprintf(doc, "Correo: %s\n",correo);
			break;
		}
		else{
			std::cout <<RED<< "\nLo sentimos, el correo ingresado no cumple los requisitos.\n" <<RESET;
		}
	}while(true);
}	

void Persona::ingresar_Genero(FILE *doc)
{
	do{
		cout << "\nG"<<char(130)<<"nero Femenino(F)/Masculino(M): "; //Genero: F/M
		cin >> genero;
		cin.ignore();

		if (Longitud(genero,'\0')==1) {
			if (genero[0]=='F' || genero[0] == 'f' || genero[0] == 'M'|| genero[0] == 'm') {
				for (int i = 0; genero[i]; i++) {
					genero[i] = toupper(genero[i]);
				}
				fprintf(doc, "Genero: %s\n",genero);
				break;
			} 
			else {
				cout <<RED<< "\nEl g"<<char(130)<<"nero especificado no es reconocido. Por favor, elige entre las opciones proporcionadas.\n" <<RESET;
			}
		} 
		else {
			cout <<RED<< "\nPor favor, ingresa un solo car"<<char(160)<<"cter.\n"<<RESET;
		}
	}while(true);
}	

void Persona::ingresar_Direccion(FILE *doc)
{
	do {
		cout << "\nDirecci"<<char(162)<<"n: ";  
		cin.getline(direccion, 50);
		if (Longitud(direccion,'\0')<10) {  //Dirección: MIN 9 
			std::cout <<RED<< "\nEs muy corto.\n" <<RESET;
		}
		else if (Longitud(direccion,'\0')>30) {  //Nombre: MAX 
			std::cout <<RED<< "\nEs muy largo.\n" <<RESET;
		}
		else {
			fprintf(doc, "Direccion: %s\n",direccion);
			break;
		}
	} while (true);
}	
void Persona::ingresarNombreUsuario(FILE* doc) {
	cout << "\nNombre de usuario: ";
	cin >> nombreUsuario;
	cin.ignore();
	fprintf(doc, "Nombre de usuario: %s\n", nombreUsuario);
}

void Persona::ingresarContrasena(FILE* doc) {
	cout << "\nContrase"<<char(164)<<"a: ";
	cin >> contrasena;
	cin.ignore();
	fprintf(doc, "Contrasena: %s\n", contrasena);
}


bool Persona::autenticar(const char* nombreUsuarioInput, const char* contrasenaInput) {
    FILE* archivoClientes = fopen("Clientes.txt", "r");
    bool autenticado = false;

    if (archivoClientes) {
        char linea[200]; // Ajusta el tamaño según la longitud máxima de una línea en tu archivo
        char usuarioGuardado[50];
        char contrasenaGuardada[50];
        bool leerUsuario = false;

        while (fgets(linea, sizeof(linea), archivoClientes)) {
            if (strstr(linea, "Nombre de usuario:")) {
                sscanf(linea, "Nombre de usuario: %s", usuarioGuardado);
                leerUsuario = true;
            } else if (strstr(linea, "Contrasena:")) {
                sscanf(linea, "Contrasena: %s", contrasenaGuardada);
                leerUsuario = false;

                // Compara los datos con la entrada proporcionada
                if (strcmp(nombreUsuarioInput, usuarioGuardado) == 0 && strcmp(contrasenaInput, contrasenaGuardada) == 0) {
                    autenticado = true; // Se encontró una coincidencia
                    break; // Salir del bucle una vez encontrada la coincidencia
                }
            }
        }
        fclose(archivoClientes);
    } else {
        cout << "Error al abrir el archivo.\n";
    }
    return autenticado; // Devolver el resultado después de recorrer todo el archivo
}
void Persona::ingresarInformacion(FILE *doc) {
	//Usuario
	ingresarNombreUsuario(doc);
	//Contraseña
	ingresarContrasena(doc);
	//Nombre
	ingresar_nombre(doc);
	//Apellido
	ingresar_apellido(doc);
	//DNI
	ingresar_DNI(doc);
	//Edad
	ingresar_Edad(doc);
	//Celular
	ingresar_Celular(doc);
	//Correo
	ingresar_Correo(doc);
	//Genero
	ingresar_Genero(doc);
	//Direccion
	ingresar_Direccion(doc);
}

void Persona::mostrarInformacion() {
	std::cout << GREEN <<"\n\tNOMBRE\t\tAPELLIDO\t\tDNI\t\tCORREO \n"<< RESET;
	printf("\n %-22s %-23s %-15s %s \n",nombre,apellido,dni,correo);
	std::cout << GREEN <<"\n\tCELULAR\t\tEDAD\t\t\tGENERO\t\tDIRECCION \n"<< RESET;
	printf("\n %-22s %-23d %-15s %s \n",celular,*edad,genero,direccion);
	std::cout << GREEN <<"\n\tUSUARIO\t\tCONTRASENA \n"<< RESET;
	printf("\n %-22s %-23s \n",nombreUsuario,contrasena);
}