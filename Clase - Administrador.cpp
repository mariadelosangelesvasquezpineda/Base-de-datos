//Empleado.cpp
#include "Clase - Administrador.h"
#include <cstring>
#include <windows.h>
#include <limits>
#include "Define - colores.h"
using namespace std;
void Administrador::ignoreLine(){
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Administrador::ingresarEmpleado(FILE *doc) { //Ingresar el salario, cargo y estado.
	do{
		cout << "\nSalario: S/.";
		if (cin >> *salario){
			if (*salario>=1000) {
				fprintf(doc, "Salario: S/.%d\n",*salario);
				break;
			}
			else 
			{
			cout << "Por favor, ingresa un salario v"<<char(160)<<"lido." << "\n";
			}
		}
		else
		{
			cout<< "Por favor, ingresa un n"<<char(163)<<"mero v"<<char(160)<<"lido.\n";
			cin.clear();
			ignoreLine();
		}
	}while(true);


	cout << "\nCargo: ";
	cin.ignore();
	cin.getline(cargo, 50);
	fprintf(doc, "Cargo: %s\n",cargo);

	cout << "\nEstado: ";
	cin.ignore();
	cin.getline(estado, 50);
	fprintf(doc, "Estado: %s\n",estado);
	
}

void Administrador::mostrarempleado() {
	cout << GREEN <<"\n\tSALARIO\t\tCARGO\t\t\tESTADO"<< RESET<< "\n";
	printf("\n S/.%-19d %-23s %s \n",*salario,cargo,estado);
}

void Administrador::mostrarEmpleados(Administrador* empleados[], int cantidad_Empleados) {
cout << LBLUE <<"EMPLEADOS REGISTRADOS\n"<<RESET;
	for (int i = 0; i < cantidad_Empleados; i++) {
		cout << LBLUE <<"______________________________________________________________________________\n"<<RESET;
		cout << GREEN<<"\n\t\t\t\tEmpleado " << i+1 <<RESET<< "\n";
		empleados[i]->mostrarInformacion();
		empleados[i]->mostrarempleado();
		cout << "\n";
	}
}

void Administrador::empleadoModificar(FILE* doc) {
	do{
		std::cout << "Modificando Empleado\n";
		int opcion;
		std::cout << "Que desea modificar?\n";
		std::cout << "1. Nombre\n2. Apellido\n3. Edad\n4. Celular\n5. Correo\n6. Genero\n7. Direccion\n8. Salario\n9. Cargo\n10. Estado\nIngrese su opcion: ";
		std::cin >> opcion;
		std::cin.ignore();
			switch (opcion) {
				case 1:
					std::cout << "Ingrese el nuevo nombre: ";
					std::cin.getline(nombre, sizeof(nombre)); //Permite leer una linea completa hasta el salto de línea 
					fprintf(doc, "Nombre: %s\n", nombre);
					break;
				case 2:
					std::cout << "Ingrese el nuevo apellido: ";
					std::cin.getline(apellido, sizeof(apellido));
					fprintf(doc, "Apellido: %s\n", apellido);
					break;
				case 3:
					std::cout << "Ingrese la nueva edad: ";
					std::cin >> *edad;
					std::cin.ignore();
					fprintf(doc, "Edad: %d\n", *edad);
					break;
				case 4:
					std::cout << "Ingrese el nuevo celular: ";
					std::cin.getline(celular, sizeof(celular));
					fprintf(doc, "Celular: %s\n", celular);
					break;
				case 5:
					std::cout << "Ingrese el nuevo correo: ";
					std::cin.getline(correo, sizeof(correo));
					fprintf(doc, "Correo: %s\n", correo);
					break;
				case 6:
					std::cout << "Ingrese el nuevo genero: ";
					std::cin >> genero;
					std::cin.ignore();
					fprintf(doc, "Genero: %c\n", genero);
					break;
				case 7:
					std::cout << "Ingrese la nueva direccion: ";
					std::cin.getline(direccion, sizeof(direccion));
					fprintf(doc, "Direccion: %s\n", direccion);
					break;
				case 8:
					cout << "Ingrese el nuevo salario: ";
					cin >> *salario;
					cin.ignore(); 
					fprintf(doc, "Salario: $%d\n", *salario);
					break;
				case 9:
					cout << "Ingrese el nuevo cargo: ";
					cin.getline(cargo, sizeof(cargo));
					fprintf(doc, "Cargo: %s\n", cargo);
					break;
				case 10:
					cout << "Ingrese el nuevo estado: ";
					cin.getline(estado, sizeof(estado));
					fprintf(doc, "Estado: %s\n", estado);
					break;
				default:
					std::cout << "Opción invalida.\n";
					Sleep(1000);
					break;
			}
		char respuesta;
		cout<< CYAN <<"\nDesea seguir modificando? (S/N): "<<RESET;
		cin>>respuesta;
		if (respuesta == 'N' || respuesta == 'n'){
			break;
		}
	}while(true);
}

void Administrador::eliminarEmpleado(Administrador* empleados[], int& cantidadEmpleados) {
	int numeroEmpleado;
	do{
		cout << "Ingrese el numero de empleado a eliminar: ";
		cin >> numeroEmpleado;
		cin.ignore();
		if (numeroEmpleado >= 1 && numeroEmpleado <= cantidadEmpleados) {
			for (int i = numeroEmpleado - 1; i < cantidadEmpleados - 1; i++) {
				empleados[i] = empleados[i + 1];
			}
			cantidadEmpleados--;
			cout <<GREEN<< "Empleado eliminado con exito.\n"<<RESET;
			Sleep(700);
			break;
		} else {
			cout <<RED<< "\nNumero de producto invalido.\n" <<RESET;
			Sleep(700);
		}
	}while(true);
}
bool Administrador::iniciarSesionAdministrador(const char* nombreUsuario, const char* contrasena) {
	return autenticar(nombreUsuario, contrasena);
}
