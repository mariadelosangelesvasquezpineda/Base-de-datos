//Menu.cpp
#include "Clase - Menu.h"

using namespace std;

void Menu::ignoreLine(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Menu::menu_principal(int &opcion){
	system("cls");
	cout << LBLUE << "\tMENU\n___________________________\n\n"<<RESET;
	cout << "1. CLIENTES\n\n";
	cout << "2. TRABAJADORES\n\n";
	cout << "0. SALIR\n";
	cout << CYAN << "\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
	
}

int Menu::menu_cliente(int &opcion){
	system("cls");
	cout << LBLUE <<"Bienvenido usuario\n___________________________\n\n"<<RESET;
	cout << "1. Registrarse\n";
	cout << "2. Iniciar sesion\n";
	cout << "3. Ver catalogo de ropa\n";
	cout << "4. Ver carrito de compras (aun no implementado)\n";
	cout << "5. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;	
}

int Menu::menu_vendedor(int &opcion){
	system("cls");
	cout << LBLUE <<"Bienvenido Vendedor\n___________________________\n\n"<<RESET;
	cout << "1. Registrar\n";
	cout << "2. Mostrar Todos los Registros\n";
	cout << "3. Buscar productos\n";
	cout << "4. Buscar Clientes\n";
	cout << "5. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
}

int Menu::menu_admin(int &opcion){
	system("cls");
	cout << LBLUE <<"Bienvenido Administrador\n___________________________\n\n"<<RESET;
	cout << "1. Registrar\n";
	cout << "2. Mostrar Todos los Registros\n";
	cout << "3. Buscar\n";
	cout << "4. Editar\n";
	cout << "5. Eliminar\n";
	cout << "6. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
}

int Menu::menu_registro(int &opcion){
	system("cls");
	cout << LBLUE <<"REGISTRO\n___________________________\n\n"<<RESET;
	cout << "1. Registrar Cliente\n";
	cout << "2. Registrar Empleado\n";
	cout << "3. Registrar Productos\n";
	cout << "4. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
}

int Menu::menu_mostrar(int &opcion){
	cout << LBLUE <<"\nMostrar Registros:\n___________________________\n\n"<<RESET;
	cout << "1. Mostrar Clientes\n";
	cout << "2. Mostrar Empleados\n";
	cout << "3. Mostrar Productos\n";
	cout << "4. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore(); 
	return opcion;
}

int Menu::menu_modificar(int &opcion){
	system("cls");
	cout << LBLUE <<"EDICION\n___________________________\n\n"<<RESET;
	cout << "1. Modificar Clientes\n";
	cout << "2. Modificar Empleados\n";
	cout << "3. Modificar Productos\n";
	cout << "4. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
}

int Menu::menu_eliminar(int &opcion){
	system("cls");
	cout << LBLUE <<"ELIMINAR\n___________________________\n\n"<<RESET;
	cout << "1. Eliminar Clientes\n";
	cout << "2. Eliminar Empleados\n";
	cout << "3. Eliminar Productos\n";
	cout << "4. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
}

int Menu::menu_buscar(int &opcion){
	system("cls");
	cout << LBLUE <<"BUSQUEDA\n___________________________\n\n"<<RESET;
	cout << "1. Buscar Clientes\n";
	cout << "2. Buscar Vendedores\n";
	cout << "3. Buscar Productos\n";
	cout << "4. Regresar\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore();
	return opcion;
}

int Menu::buscar_clientes(int &opcion){
	cout << GREEN <<"\nBuscador de Clientes:\n___________________________\n\n"<<RESET;
	cout << "1. Buscar por Inicial\n";
	cout << "2. Buscar por Nombre\n";
	cout << "3. Buscar por Apellido\n";
	cout << "4. Buscar por DNI\n";
	cout << "5. Buscar por Edad\n";
	cout << "6. Buscar por G"<<char(130)<<"nero\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore(); 
	return opcion;
}

int Menu::buscar_vendedores(int &opcion){
	cout << GREEN <<"\nBuscador de Vendedores:\n___________________________\n\n"<<RESET;
	cout << "1. Buscar por Inicial\n";
	cout << "2. Buscar por Nombre\n";
	cout << "3. Buscar por Apellido\n";
	cout << "4. Buscar por DNI\n";
	cout << "5. Buscar por Edad\n";
	cout << "6. Buscar por G"<<char(130)<<"nero\n";
	cout << CYAN <<"\nIngrese su opcion: "<<RESET;
	cin >> opcion;
	cin.ignore(); 
	return opcion;
}

void Menu::menuClientes(Cliente *clientes[], int &cantidad_Clientes, FILE* doc_clientes,Productos *productos[], int &cantidad_Productos, FILE* doc_productos, int &opcion, Cliente *cliente)
{
	do{
		menu_cliente(opcion);
		switch (opcion){
			case 1:
			{	
				system("cls");
				cout << LBLUE <<"REGISTRO DE USUARIO\n"<<RESET;
				cliente->ingresarInformacion(doc_clientes);
				clientes[cantidad_Clientes] = cliente; //agregamos en la posicion de cantidad de clientes.
				cantidad_Clientes++; //aumentamos
				break;
			}
			case 2:{
				system("cls");
				char nombreUsuarioInput[50];
				char contrasenaInput[50];

				doc_clientes = fopen("Clientes.txt", "r");

				if (doc_clientes) {
					cout << LBLUE <<"INICIO DE SESI"<<char(224)<<"N\n"<<RESET;
					do{
						cout << "\nIngrese nombre de usuario: ";
						cin >> nombreUsuarioInput;

						cout << "Ingrese contrase"<<char(164)<<"a: ";
						cin >> contrasenaInput;
						if (cliente->iniciarSesionCliente(nombreUsuarioInput, contrasenaInput)) {
							cout << "\nInicio de sesion exitoso. Bienvenido, cliente!\n";
							Sleep(700);
							break;
							// Lógica adicional después de iniciar sesión...
						} else {
							cout << "\nInicio de sesion fallido. Credenciales incorrectas.\n";
							Sleep(700);
							
						}
					}while(true);
				} else {
					cout << "Error al abrir el archivo.\n";
				}
				break;
			}
			case 3:
			{
				system("cls");
				char respuesta;
				cout << LBLUE <<"CATALOGO DE ROPA\n\n";
				productos[cantidad_Productos]->mostrarProductos(productos,cantidad_Productos);
				do{
					cout << "Escriba 'S' si desea salir del catalogo: ";
					cin >> respuesta;
					cin.ignore();
					if (respuesta=='S'||respuesta=='s'){
						break;
					}
				}while(true);
				break;
			}
			case 4: 
			{
				break;
			}
			case 5:
				break;
			default:{
				cout <<  RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
				Sleep(700);
			}
		}
	} while(opcion != 5);
}

void Menu::menuAdmin(Cliente *clientes[], int &cantidad_Clientes, Administrador *empleados[], int &cantidad_Empleados, Productos *productos[], int &cantidad_Productos, FILE* doc_clientes, FILE* doc_empleados, FILE* doc_productos, int &opcion)
{
	do {
		menu_admin(opcion);
		switch(opcion) {
			case 1:{
				do{
					menu_registro(opcion);
					switch(opcion) {
						case 1:{
							do{
								Cliente *cliente = new Cliente;
								system("cls");
								cout << LBLUE <<"REGISTRO DE CLIENTE\n"<<RESET;
								cliente->ingresarInformacion(doc_clientes);
								clientes[cantidad_Clientes] = cliente;
								cantidad_Clientes++;
								char respuesta_1;
								cout<< CYAN <<"\nDesea registrar otro cliente? (S/N): "<<RESET;
								cin>>respuesta_1;
								if (respuesta_1 == 'N' || respuesta_1 == 'n'){
									break;
								}
								
							}while(true);
							break;
						}
						case 2:{ 
							do {
								system("cls");
								Administrador *empleado = new Administrador;
								cout << LBLUE <<"REGISTRO DE EMPLEADOS\n"<<RESET;
								empleado->ingresarInformacion(doc_empleados);
								empleado->ingresarEmpleado(doc_empleados);
								empleados[cantidad_Empleados] = empleado;
								cantidad_Empleados++;
								char respuesta_2;
								cout<< CYAN <<"\nDesea registrar otro empleado? (S/N): "<<RESET;
								cin>>respuesta_2;
								if (respuesta_2 == 'N' || respuesta_2 == 'n'){
									break;
								}
							}while(true);
							break;
						}
						case 3:{
							do {
								system("cls");
								Productos *producto = new Productos;
								cout << LBLUE <<"REGISTRO DE PRODUCTOS\n"<<RESET;
								producto->ingresarProducto(doc_productos);
								productos[cantidad_Productos] = producto;
								cantidad_Productos++;
								char respuesta_3;
								cout<< CYAN <<"\nDesea registrar otro producto? (S/N): "<<RESET;
								cin>>respuesta_3;
								if (respuesta_3 == 'N' || respuesta_3 == 'n'){
									break;
								}
							}while (true);
							break;
						}
						case 4:{
							break;
						}
						default:
							cout << RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
							Sleep(700);
					}
				}while(opcion!=4);
				break;
			}
			case 2:{
				do {
					menu_mostrar(opcion);
					switch(opcion) {
						case 1:{
							system("cls");
							clientes[cantidad_Clientes]->mostrarClientes(clientes, cantidad_Clientes);
							break;  
						}										
						case 2:{			
							system("cls");
							empleados[cantidad_Empleados]->mostrarEmpleados(empleados, cantidad_Empleados);
							break; 
						}										
						case 3:{
							system("cls");
							cout << LBLUE <<"PRODUCTOS REGISTRADOS\n"<<RESET;
							productos[cantidad_Productos]->mostrarProductos(productos,cantidad_Productos);
							break;
						}
						case 4:{									
							break;
						}
						default:
							cout << RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
							Sleep(700);
					}
				} while(opcion != 4);
				break;
			}
			case 3:{
				do{
					menu_buscar(opcion);
					switch (opcion){
						case 1:{
							buscar_clientes(opcion);
							Lista_Clientes lista_clientes;
								switch(opcion){
									case 1:{
										char respuesta_7;
										do{
											char inicial;
											cout<<CYAN<<"\nIngrese la inicial buscada: "<<RESET;
											cin>>inicial;
											cin.ignore();
											if(lista_clientes.buscar_inicial(clientes, cantidad_Clientes, inicial))
											{
												cout<<"Cliente(s) encontrado(s) con la letra "<<GREEN<<inicial<<RESET<<"\n";
											}
											else{ cout<<"No existen clientes con la letra "<<GREEN<<inicial<<RESET<<"\n";}
											cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
											cin>>respuesta_7;
											cin.ignore();
										}while (respuesta_7 != 'N' && respuesta_7!= 'n');
										break;	
									}
									case 2:{
										char respuesta_4;
										do{
											char nombre_buscado[10];
											cout<<CYAN<<"\nIngrese el nombre buscado: "<<RESET;
											cin.getline(nombre_buscado,50);
											if(lista_clientes.buscar_nombre(clientes, cantidad_Clientes, nombre_buscado))
											{
												cout<<"\nCliente(s) encontrado(s)\n";
											}
											else{ cout<<"\nNo existen clientes con el nombre "<<GREEN<<nombre_buscado<<RESET<<"\n";}
											cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
											cin>>respuesta_4;
											cin.ignore();
										}while (respuesta_4 != 'N' && respuesta_4 != 'n');
										break;
									}
									case 3:{
										char respuesta_5;
										do{
											char apellido_buscado[10];
											cout<<CYAN<<"\nIngrese el apellido buscado: "<<RESET;
											cin.getline(apellido_buscado,50);
											if(lista_clientes.buscar_apellido(clientes, cantidad_Clientes, apellido_buscado))
											{
												cout<<"\nCliente(s) encontrado(s) con el apellido "<<apellido_buscado<<"\n";
											}
											else{ cout<<"\nNo existen clientes con el apellido "<<GREEN<<apellido_buscado<<RESET<<"\n";}
												cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
												cin>>respuesta_5;
												cin.ignore();
										}while (respuesta_5 != 'N' && respuesta_5 != 'n');
										break;
									}
									case 4:{
										char respuesta_6;
										do{
											char dni_buscado[10];
											cout<<CYAN<<"\nIngrese el DNI buscado: "<<RESET;
											cin.getline(dni_buscado,50);
											if(lista_clientes.buscar_dni(clientes, cantidad_Clientes, dni_buscado))
											{
												cout<<"\nCliente(s) encontrado(s) con el DNI "<<dni_buscado<<"\n";
											}
											else{ cout<<"\nNo existen clientes con el con el DNI "<<GREEN<<dni_buscado<<RESET<<"\n"; }
												cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
												cin>>respuesta_6;
												cin.ignore();
										}while (respuesta_6 != 'N' && respuesta_6 != 'n');
										break;
									}
									case 5:{
										char respuesta_8;
										do{
											char genero_buscado;
											cout<<CYAN<<"\nIngrese el Genero buscado (F/M): "<<RESET;
											cin>>genero_buscado;
											if(lista_clientes.buscar_genero(clientes, cantidad_Clientes, genero_buscado))
											{
												cout<<"\nCliente(s) encontrado(s) con el Genero "<<genero_buscado<<"\n";
											}
											else{ cout<<"\nNo existen clientes con el Genero "<<GREEN<<genero_buscado<<RESET<<"\n"; }
												cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
												cin>>respuesta_8;
												cin.ignore();
										}while (respuesta_8 != 'N' && respuesta_8 != 'n');
										break;
									}
									case 6:{
										break;
									}
								}
							break;
						}
						case 2:{
							buscar_vendedores(opcion);
							Lista_Empleados lista_empleados;
								switch(opcion){
									case 1:{
										char respuesta_7;
										do{
											char inicial;
											cout<<CYAN<<"\nIngrese la inicial buscada: "<<RESET;
											cin>>inicial;
											cin.ignore();
											if(lista_empleados.buscar_inicial(empleados, cantidad_Empleados, inicial))
											{
												cout<<"Cliente(s) encontrado(s) con la letra "<<GREEN<<inicial<<RESET<<"\n";
											}
											else{ cout<<"No existen clientes con la letra "<<GREEN<<inicial<<RESET<<"\n";}
											cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
											cin>>respuesta_7;
											cin.ignore();
										}while (respuesta_7 != 'N' && respuesta_7!= 'n');
										break;	
									}
									case 2:{
										char respuesta_4;
										do{
											char nombre_buscado[10];
											cout<<CYAN<<"\nIngrese el nombre buscado: "<<RESET;
											cin.getline(nombre_buscado,50);
											if(lista_empleados.buscar_nombre(empleados, cantidad_Empleados, nombre_buscado))
											{
												cout<<"\nCliente(s) encontrado(s)\n";
											}
											else{ cout<<"\nNo existen clientes con el nombre "<<GREEN<<nombre_buscado<<RESET<<"\n";}
											cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
											cin>>respuesta_4;
											cin.ignore();
										}while (respuesta_4 != 'N' && respuesta_4 != 'n');
										break;
									}
									case 3:{
										char respuesta_5;
										do{
											char apellido_buscado[10];
											cout<<CYAN<<"\nIngrese el apellido buscado: "<<RESET;
											cin.getline(apellido_buscado,50);
											if(lista_empleados.buscar_apellido(empleados, cantidad_Empleados, apellido_buscado))
											{
												cout<<"\nCliente(s) encontrado(s) con el apellido "<<apellido_buscado<<"\n";
											}
											else{ cout<<"\nNo existen clientes con el apellido "<<GREEN<<apellido_buscado<<RESET<<"\n";}
												cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
												cin>>respuesta_5;
												cin.ignore();
										}while (respuesta_5 != 'N' && respuesta_5 != 'n');
										break;
									}
									case 4:{
										char respuesta_6;
										do{
											char dni_buscado[10];
											cout<<CYAN<<"\nIngrese el DNI buscado: "<<RESET;
											cin.getline(dni_buscado,50);
											if(lista_empleados.buscar_dni(empleados, cantidad_Empleados, dni_buscado))
											{
												cout<<"\nCliente(s) encontrado(s) con el DNI "<<dni_buscado<<"\n";
											}
											else{ cout<<"\nNo existen clientes con el con el DNI "<<GREEN<<dni_buscado<<RESET<<"\n"; }
												cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
												cin>>respuesta_6;
												cin.ignore();
										}while (respuesta_6 != 'N' && respuesta_6 != 'n');
										break;
									}
									case 5:{
										char respuesta_8;
										do{
											char genero_buscado;
											cout<<CYAN<<"\nIngrese el Genero buscado (F/M): "<<RESET;
											cin>>genero_buscado;
											if(lista_empleados.buscar_genero(empleados, cantidad_Empleados, genero_buscado))
											{
												cout<<"\nCliente(s) encontrado(s) con el Genero "<<genero_buscado<<"\n";
											}
											else{ cout<<"\nNo existen clientes con el Genero "<<GREEN<<genero_buscado<<RESET<<"\n"; }
												cout<< CYAN <<"\nDesea realizar otra busqueda? (S/N): "<<RESET;
												cin>>respuesta_8;
												cin.ignore();
										}while (respuesta_8 != 'N' && respuesta_8 != 'n');
										break;
									}
									case 6:{
										break;
									}
								}
							break;
						}
						case 3:{
							break;
						}	
						case 4:{
							break;
						}
						default:
							cout << RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
							Sleep(700);
					}
				}while(opcion !=4);
				break;
			}
			case 4:{
				do {
					menu_modificar(opcion);
					switch(opcion) {
						case 1:{
							if (cantidad_Clientes>=1)
							{
								do{
									int numero_cliente;
									clientes[cantidad_Clientes]->mostrarClientes(clientes, cantidad_Clientes);
									cout << "Ingrese el numero de cliente a modificar: ";
									cin >> numero_cliente;
									cin.ignore();
									if (numero_cliente >= 1 && numero_cliente <= cantidad_Clientes) {
										clientes[numero_cliente - 1]->clienteModificar(doc_clientes); 
										break;
									} else {
										cout << "Numero de cliente invalido\n";
										system("pause");
									}
								}while(true);
							}
							else
							{
								cout<<RED<<"\nNo hay clientes registrados. Registre uno para comenzar a modificar\n"<<RESET;
								system("pause");
							}
							break;
						}
						case 2:{
							if (cantidad_Empleados>=1)
							{
								do{
									int empleadoModificar;
									cout << "Ingrese el numero de empleado a modificar: ";
									cin >> empleadoModificar;
									cin.ignore();
									if (empleadoModificar >= 1 && empleadoModificar <= cantidad_Empleados) {
										empleados[empleadoModificar - 1]->empleadoModificar(doc_empleados); 
										break;
									} 
									else {
										cout << "Numero de empleado invalido\n";
										system("pause");
									}
								}while(true);
							}
							else
							{
								cout<<RED<<"\nNo hay empleados registrados. Registre uno para comenzar a modificar\n"<<RESET;
								system("pause");
							}
							break;
						}
						case 3:{
							if (cantidad_Clientes>=1)
							{
								do{
									int productoModificar;
									cout << "Ingrese el numero del producto a modificar: ";
									cin >> productoModificar;
									cin.ignore();
									if (productoModificar >= 1 && productoModificar <= cantidad_Productos) {
										productos[productoModificar - 1]->productoModificar(doc_productos); 
										break;
									} 
									else {
										cout << "Numero de producto invalido\n";
									}
								}while(true);
							}
							else
							{
								cout<<RED<<"\nNo hay productos registrados. Registre uno para comenzar a modificar\n"<<RESET;
								system("pause");
							}
							break;
						}
						case 4:{
							break;
						}
						default:
							cout << RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
							Sleep(700);
					}
				} while(opcion != 4);
				break;
			}
			case 5:{
				do {
					menu_eliminar(opcion);			
					switch(opcion) {
						case 1:{
							clientes[cantidad_Clientes]->eliminarCliente(clientes, cantidad_Clientes);
							break;
						}
						case 2:{
							empleados[cantidad_Empleados]->eliminarEmpleado(empleados, cantidad_Empleados);
							break;
						}
						case 3:{
							productos[cantidad_Productos]->eliminarProducto(productos, cantidad_Productos);
							break;
						}
						case 4:{
							break;
						}
						default:
							cout << RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
							Sleep(700);
					}
				} while(opcion!= 4);
				break;
			}
			case 6:{
				break;
			}
			default:
				cout << RED <<"\nOpcion invalida. Por favor, ingrese una opcion valida.\n"<<RESET;
				Sleep(700);
		}
	} while(opcion != 6);
}

