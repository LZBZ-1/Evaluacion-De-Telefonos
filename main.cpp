#include <iostream>
#include "./Views/TelefonoVista.h"
#include "./Views/PersonaVista.h"

using namespace std;

int main() {
    int opcionPrincipal;
    int opcionSubMenu;
    int opcion;
    unsigned int numero;
    unsigned int dni;
    string operador;
    string nombre;
    string plan;
    string apellido;
    Telefono telefono;
    Usuario usuario;
    usuarios.cargarUsuariosDesdeArchivo();
	telefonos.cargarTelefonosDesdeArchivo();
	control.cargarNumeros(usuarios,telefonos);

    do {
        cout << "----- Menu Principal -----" << endl;
        cout << "1. Telefono" << endl;
        cout << "2. Usuarios" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1:
                do {
                    cout << endl;
                    cout << "----- Telefonos -----" << endl;
                    cout << "1. Mostrar Titular Linea" << endl;
                    cout << "2. Agregar Telefono" << endl;
                    cout << "3. Buscar Operador Telefono" << endl;
                    cout << "4. Desactivar Linea" << endl;
                    cout << "5. Activar Linea" << endl;
                    cout << "6. Volver al menu principal" << endl;
                    cout << "Ingrese su opcion: ";
                    cin >> opcionSubMenu;

                    switch (opcionSubMenu) {
                        case 1:
                            do {
        						cout << "Ingrese su numero: ";
        						cin >> numero;

        						if (numero < 900000000 || numero > 999999999) {
            						cout << "Numero No Valida." << endl;
        						}
    						} while (numero < 900000000 || numero > 999999999);
							cout << endl;
							mostrarTitular(numero);
                            break;
                        case 2:
                            do {
        						cout << "Ingrese el nuevo numero: ";
        						cin >> numero;

        						if (numero < 900000000 || numero > 999999999) {
            						cout << "Numero No Valida." << endl;
        						}
    						} while (numero < 900000000 || numero > 999999999);
    						do {
        						cout << "Ingrese el dni: ";
        						cin >> dni;

        						if (dni < 10000000 || dni > 99999999) {
            						cout << "DNI No Valida." << endl;
        						}
    						} while (dni < 10000000 || dni > 99999999);
    						cout << "Ingrese su Nombre: ";
    						cin >> nombre;
    						cout << "Ingrese su apellido: ";
    						cin >> apellido;
    						nombre += " " + apellido;
    						usuario.setDni(dni);
    						usuario.setNombreApellido(nombre);
    						agregarUsuario(usuario);
    						cout << "Indique el nombre del operador: ";
    						cin >> operador;
    						cout << "Ingrese el tipo de Plan: ";
    						cin >> plan;
    						telefono.setNumero(numero);
    						telefono.setActivo(true);
    						telefono.setOperadora(operador);
    						telefono.setTipoPlan(plan);
    						telefono.setDniUsuario(dni);
    						agregarTelefono(telefono);
    						usuarios.cargarUsuariosDesdeArchivo();
							telefonos.cargarTelefonosDesdeArchivo();
							control.cargarNumeros(usuarios,telefonos);
                            break;
                        case 3:
                            do {
        						cout << "Ingrese su numero ";
        						cin >> numero;

        						if (numero <= 900000000 || numero >= 999999999) {
            						cout << "Número No Valida." << endl;
        						}
    						} while (numero <= 900000000 || numero >= 999999999);
							buscarOperador(numero);
                            break;
                        case 4:
                            do {
        						cout << "Ingrese su numero ";
        						cin >> numero;

        						if (numero <= 900000000 || numero >= 999999999) {
            						cout << "Numero No Valida." << endl;
        						}
    						} while (numero <= 900000000 || numero >= 999999999);
							desactivarLinea(numero);
                            break;
                        case 5:
                            do {
        						cout << "Ingrese su numero ";
        						cin >> numero;

        						if (numero <= 900000000 || numero >= 999999999) {
            						cout << "Numero No Valida." << endl;
        						}
    						} while (numero < 900000000 || numero > 999999999);
							activarLinea(numero);
                            break;    
                        case 6:
                        	system("cls");
                            cout << "Volviendo al menu principal." << endl;
                            system("pause");
                            system("cls");
                            break;
                        default:
                        	system("cls");
                            cout << "Opción invalida. Por favor, ingrese una opcion válida." << endl;
                            break;
                    }
                } while (opcionSubMenu != 6);
                break;
            case 2:
                do {
        			cout << "----- Menu -----" << endl;
			        cout << "1. Crear usuario" << endl;
			        cout << "2. Mostrar telefono" << endl;
			        cout << "3. Salir" << endl;
        			cout << "Ingrese su opcion: ";
        			cin >> opcion;

			        switch (opcion) {
			            case 1:
			                do {
        						cout << "Ingrese el dni: ";
        						cin >> dni;

        						if (dni < 10000000 || dni > 99999999) {
            						cout << "DNI No Valida." << endl;
        						}
    						} while (dni < 10000000 || dni > 99999999);
    						cout << "Ingrese su Nombre: ";
    						cin >> nombre;
    						cout << "Ingrese su apellido: ";
    						cin >> apellido;
    						nombre += " " + apellido;
    						usuario.setDni(dni);
    						usuario.setNombreApellido(nombre);
    						agregarUsuario(usuario);
               				break;
            			case 2:
                			do {
        						cout << "Ingrese el dni: ";
        						cin >> dni;

        						if (dni < 10000000 || dni > 99999999) {
            						cout << "DNI No Valida." << endl;
        						}
    						} while (dni < 10000000 || dni > 99999999);
    						mostrarLineas(dni);
                			break;
            			case 3:
            				system("cls");
                			cout << "Volviendo al menu principal." << endl;
                            break;
            			default:
            				system("cls");
                			cout << "Opción invalida. Por favor, ingrese una opción valida." << endl;
                			break;
        			}

    			} while (opcion != 3);
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                break;
        }

    } while (opcionPrincipal != 3);

    return 0;
}