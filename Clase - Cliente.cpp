//Cliente.cpp
#include "Clase - Cliente.h"
#include <windows.h>
#include "Define - colores.h"
using namespace std;


void Cliente::mostrarClientes(Cliente *clientes[], int cantidad_Clientes) {
cout << LBLUE <<"CLIENTES REGISTRADOS\n"<<RESET;
	for (int i = 0; i < cantidad_Clientes; i++) {
		cout << LBLUE <<"______________________________________________________________________________\n"<<RESET;
		cout << GREEN<<"\n\t\t\t\tCliente " << i+1 <<RESET<< "\n";
		clientes[i]->mostrarInformacion();
		cout << "\n";
	}
}

void Cliente::clienteModificar(FILE* doc) {
	cout << "Modificando Cliente\n";

	int opcion;
	cout << GREEN <<char(168)<<"Que datos desea modificar?\n"<< RESET;
	cout << "1. Nombre\n2. Apellido\n3. Edad\n4. Celular\n5. Correo\n6. Genero\n7. Direccion\nIngrese su opcion: ";
	cin >> opcion;
	cin.ignore();

	switch (opcion) {
		case 1:
			cout << "Ingrese el nuevo nombre: ";
			cin.getline(nombre, sizeof(nombre));
			fprintf(doc, "Nombre: %s\n", nombre);
			break;
		case 2:
			cout << "Ingrese el nuevo apellido: ";
			cin.getline(apellido, sizeof(apellido));
			fprintf(doc, "Apellido: %s\n", apellido);
			break;
		case 3:
			cout << "Ingrese la nueva edad: ";
			cin >> *edad;
			cin.ignore(); 
			fprintf(doc, "Edad: %d\n", *edad);
			break;
		case 4:
			cout << "Ingrese el nuevo celular: ";
			cin.getline(celular, sizeof(celular));
			fprintf(doc, "Celular: %s\n", celular);
			break;
		case 5:
			cout << "Ingrese el nuevo correo: ";
			cin.getline(correo, sizeof(correo));
			fprintf(doc, "Correo: %s\n", correo);
			break;
		case 6:
			cout << "Ingrese el nuevo genero: ";
			cin >> genero;
			cin.ignore();
			fprintf(doc, "Genero: %c\n", genero);
			break;
		case 7:
			cout << "Ingrese la nueva direccion: ";
			cin.getline(direccion, sizeof(direccion));
			fprintf(doc, "Dirección: %s\n", direccion);
			break;
		default:
			cout << "Opción invalida.\n";
			break;
	}
}

bool Cliente::iniciarSesionCliente(const char* nombreUsuario, const char* contrasena) {
	return autenticar(nombreUsuario, contrasena);
}

void Cliente::eliminarCliente(Cliente *clientes[], int& cantidad_Clientes) {
	int numeroCliente;
	do{	
		cout << "Ingrese el numero de cliente a eliminar: ";
		cin >> numeroCliente;
		cin.ignore();

		if (numeroCliente >= 1 && numeroCliente <= cantidad_Clientes) {
			for (int i = numeroCliente - 1; i < cantidad_Clientes - 1; i++) {
				clientes[i] = clientes[i + 1];
			}
			cantidad_Clientes--;
			cout << "Cliente eliminado con exito.\n";
			Sleep(1000);
			break;
		}
		else {
			cout <<RED<< "\nNumero de cliente invalido.\n" <<RESET;
			Sleep(1000);
		}
	}while(true);
}
