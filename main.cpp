#include <iostream>
#include "./Views/TelefonoVista.h"
#include "./Views/PersonaVista.h"

using namespace std;

int main() {
    int opcionPrincipal;
    int opcionSubMenu;

    do {
        cout << "----- Menu Principal -----" << endl;
        cout << "1. TelefonoVista" << endl;
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
                    cout << "Ingrese su opción: ";
                    cin >> opcionSubMenu;

                    switch (opcionSubMenu) {
                        case 1:
                            unsigned int numero;
                            do {
        						cout << "Ingrese su numero ";
        						cin >> numero;

        						if (numero < 900000000 || numero > 999999999) {
            						cout << "Número No Valida." << endl;
        						}
    						} while (numero < 900000000 || numero > 999999999);
							mostrarTitular(numero);
                            break;
                        case 2:
                            unsigned int numero;
                            unsigned int dni
                            do {
        						cout << "Ingrese el nuevo numero";
        						cin >> numero;

        						if (numero < 900000000 || numero > 999999999) {
            						cout << "Número No Valida." << endl;
        						}
    						} while (numero < 900000000 || numero > 999999999);
    						do {
        						cout << "Ingrese el dni";
        						cin >> numero;

        						if (numero < 900000000 || numero > 999999999) {
            						cout << "Número No Valida." << endl;
        						}
    						} while (numero < 900000000 || numero > 999999999);
    						agregarUsuario(dni);
    						agregarTelefono(Telefono)
                            break;
                        case 3:
                            cout << "Ha seleccionado la Subopción 3." << endl;
                            break;
                        case 4:
                            cout << "Ha seleccionado la Subopción 4." << endl;
                            break;
                        case 5:
                            cout << "Volviendo al menú principal." << endl;
                            break;    
                        case 6:
                            cout << "Volviendo al menú principal." << endl;
                            break;
                        default:
                            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                            break;
                    }
                } while (opcionSubMenu != 6);

                break;
            case 2:
                cout << "Ha seleccionado la Opción 2." << endl;
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion inválida. Por favor, ingrese una opción valida." << endl;
                break;
        }

    } while (opcionPrincipal != 3);

    return 0;
}