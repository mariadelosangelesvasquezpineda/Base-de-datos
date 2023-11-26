//Productos.cpp
#include "Clase - Productos.h"
#include <iostream>
#include <limits>
#include <cstring>
#include <windows.h>
#include "Define - colores.h"
using namespace std;
Productos::Productos() {
	nombre = new char[50]; 
	precio = new double; 
	stock = new int;
	talla = new char[50];
	color = new char[50];
	categoria = new char[50];
	descripcion = new char[50];
} 
Productos::~Productos() {
	delete[] nombre;
	delete precio;
	delete stock;
	delete[] talla;
	delete[] color;
	delete[] categoria;
	delete[] descripcion;
} 

void Productos::setNombre(const char* newNombre) {
	strcpy(nombre, newNombre);
}

void Productos::setCategoria(const char* newCategoria) {
	strcpy(categoria, newCategoria);
}

void Productos::setPrecio(double newPrecio) {
	*precio = newPrecio;
}

void Productos::setStock(int newStock) {
	*stock = newStock;
}

void Productos::setTalla(const char* newTalla) {
	strcpy(talla, newTalla);
}

void Productos::setColor(const char* newColor) {
	strcpy(color, newColor);
}

void Productos::setDescripcion(const char* newDescripcion) {
	strcpy(descripcion, newDescripcion);
}

const char* Productos::getNombre() {
	return nombre;
}

const char* Productos::getCategoria() {
	return categoria;
}

double Productos::getPrecio() {
	return *precio;
}

int Productos::getStock() {
	return *stock;
}

const char* Productos::getTalla() {
	return talla;
}

const char* Productos::getColor() {
	return color;
}

const char* Productos::getDescripcion() {
	return descripcion;
}

void Productos::ignoreLine(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Productos::ingresarProducto(FILE *doc) {
	cout<<	"\nNombre: ";
	cin.getline(nombre, 50);
	fprintf(doc, "\nNombre: %s\n",nombre);
	
	cout<<	"\nTalla: ";
	cin.getline(talla, 50);
	fprintf(doc, "Talla: %s\n",talla);
	
	do{
		cout << "\nPrecio: S/.";
		if (cin >> *precio){
			if (*precio >= 0 && *precio<=500) {
				fprintf(doc, "Precio: %.2lf\n",*precio);
				break;
			} 
			else{
			cout << "Lo siento, el monto no cumple los requisitos." << "\n";
			}
		}
		else{
			cout<< "Por favor, ingresa un n"<<char(163)<<"mero valido.\n";
			cin.clear();
			ignoreLine();
		}
	}while(true);
	
	cin.ignore();
	cout<<	"\nCategoria: ";
	cin.getline(categoria, 50);
	fprintf(doc, "Categoria: %s\n",categoria);
	
	cout<<	"\nColor: ";
	cin.getline(color, 50);
	fprintf(doc, "Color: %s\n",color);
	
	cout<<	"\nDescripcion: ";
	cin.getline(descripcion, 50);
	fprintf(doc, "Descripcion: %s\n",descripcion);
}

void Productos::mostrarproducto() {
	cout << GREEN <<"\n\tNOMBRE\t\tTALLA\t\tPRECIO\t\tCATEGORIA "<< RESET<< "\n";
	printf("\n %-22s %-15s S/.%-12.2lf %s \n",nombre,talla,*precio,categoria);
	cout << GREEN <<"\n\tCOLOR\t\tDESCRIPCION"<< RESET<< "\n";
	printf("\n %-22s %s\n",color,descripcion);
}

void Productos::mostrarProductos(Productos *productos[], int cantidad_Productos) {
    for (int i = 0; i < cantidad_Productos; i++) {
		cout << LBLUE <<"__________________________________________________________________________\n"<<RESET;
        cout << GREEN<<"\n\t\t\t\tProducto " << i+1 <<RESET<< "\n";
        productos[i]->mostrarproducto();
        cout << "\n";
    }
}

void Productos::productoModificar(FILE* doc) {
	std::cout << "Modificando Producto\n";
	int opcion;
	std::cout << "Que desea modificar?\n";
	std::cout << "1. Nombre\n2. Talla\n3. Precio\n4. Categoría\n5. Color\n6. Descripcion\nIngrese su opcion: ";
	std::cin >> opcion;
	std::cin.ignore();
	    switch (opcion) {
            case 1:
                std::cout << "Ingrese el nuevo nombre: ";
                std::cin.getline(nombre, sizeof(nombre)); //Permite leer una linea completa hasta el salto de línea 
                fprintf(doc, "Nombre: %s\n", nombre);
                break;
            case 2:
                std::cout << "Ingrese la nueva talla: ";
                std::cin.getline(talla, sizeof(talla));
                fprintf(doc, "Talla: %s\n", talla);
                break;
            case 3:
                std::cout << "Ingrese el nuevo precio: ";
                std::cin >> *precio;
				std::cin.ignore();
                fprintf(doc, "Precio: %.2lf\n", *precio);
                break;
            case 4:
                std::cout << "Ingrese la nueva categoria: ";
                std::cin.getline(categoria, sizeof(categoria));
                fprintf(doc, "Categoria: %s\n", categoria);
                break;
            case 5:
                std::cout << "Ingrese el nuevo color: ";
                std::cin.getline(color, sizeof(color));
                fprintf(doc, "Color: %s\n", color);
                break;
			case 6:
                std::cout << "Ingrese la nueva descripcion: ";
                std::cin.getline(descripcion, sizeof(descripcion));
                fprintf(doc, "Descripcion: %s\n", descripcion);
                break;
            default:
                std::cout << "Opción invalida.\n";
				Sleep(1000);
                break;
        }
    
}

void Productos::eliminarProducto(Productos *productos[], int& cantidad_Productos) {
	int numeroProducto;
	do{	
		cout << "Ingrese el numero del producto a eliminar: ";
		cin >> numeroProducto;
		cin.ignore();

		if (numeroProducto >= 1 && numeroProducto <= cantidad_Productos) {
			for (int i = numeroProducto - 1; i < cantidad_Productos - 1; i++) {
				productos[i] = productos[i + 1];
			}
			cantidad_Productos--;
			cout << "Producto eliminado con exito.\n";
			Sleep(1000);
			break;
		}
		else {
			cout <<RED<< "\nNumero de producto invalido.\n" <<RESET;
			Sleep(1000);
		}
	}while(true);
}
