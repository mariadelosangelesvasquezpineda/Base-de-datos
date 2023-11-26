//Productos.h
#pragma once
#include <iostream>
class Productos{
private:
	char *nombre; 
	double *precio; 
	int *stock;
	char *talla;
	char *color;
	char *categoria;
	char *descripcion;
public:
	Productos();
	~Productos();
	void setNombre(const char* newNombre);
    void setCategoria(const char* newCategoria);
    void setPrecio(double newPrecio); 
	void setStock(int newStock);
    void setTalla(const char* newTalla);
    void setColor(const char* newColor);
    void setDescripcion(const char* newDescripcion);
    const char* getNombre();
    const char* getCategoria();
    double getPrecio();
	int getStock();
    const char* getTalla(); 
    const char* getColor();
    const char* getDescripcion();
	
	void ignoreLine();
	void ingresarProducto(FILE *doc);
    void mostrarproducto();
	void mostrarProductos(Productos* productos[], int cantidad_Productos);
	void eliminarProducto(Productos* productos[], int& cantidad_Productos);
	void productoModificar(FILE* doc);
};
