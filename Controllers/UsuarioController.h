#include <iostream>
#include <fstream>
#include "../Library/List.h"
#include "../Models/Usuario.h"

using namespace std;

class UsuarioController {
private:
    List<Usuario> usuarios;

public:
    UsuarioController() = default;
    ~UsuarioController() = default;

    void agregarUsuario(const Usuario& usuario) {
        usuarios.push_back(usuario);
        guardarUsuarioEnArchivo(usuario);
    }

    void mostrarUsuarios(const auto& usuario) {
        cout << "DNI: " << usuario.getDni() << endl;
        cout << "Nombre y Apellido: " << usuario.getNombreApellido() << endl;
        cout << "Sus lineas telefonicas son: " << endl;
        for(int i = 0; i < usuario.getNumeroTelefono().size(); i++) {
            cout << i << ". " << usuario.getNumeroTelefono()[i] << endl;
        }
        cout << endl;
    }

    int buscarDniPorTelefono(unsigned int numeroTelefono) {
        for (const auto& usuario : usuarios) {
            const List<unsigned int>& numeros = usuario.getNumeroTelefono();
            for (const auto& numero : numeros) {
                if (numero == numeroTelefono) {
                    return usuario.getDni();
                }
            }
        }
        return -1; // Retornar -1 si no se encuentra el número de teléfono
    }

    void guardarUsuarioEnArchivo(const Usuario& usuario) {
        const string nombreArchivo = "../Data/usuario.csv";
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Escribir datos del usuario
            archivo << usuario.getDni() << "," << usuario.getNombreApellido();
            archivo << endl;

            archivo.close();
            cout << "Datos del usuario guardados en " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }

    void actualizarArchivoCSV() {
        const string nombreArchivo = "../Data/usuario.csv";
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Escribir encabezados de columna
            archivo << "dni,nombreApellido" << endl;

            // Escribir datos de usuarios
            for (const auto& usuario : usuarios) {
                archivo << usuario.getDni() << "," << usuario.getNombreApellido();
                archivo << endl;
            }

            archivo.close();
            cout << "Archivo CSV actualizado correctamente." << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }

    void cargarUsuariosDesdeArchivo() {
        const string nombreArchivo = "../Data/usuario.csv";
        usuarios.clear();

        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Leer encabezados de columna
            string encabezados;
            getline(archivo, encabezados);

            // Leer datos de usuarios
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string dato;

                // Obtener DNI
                getline(ss, dato, ',');
                unsigned int dni = stoi(dato);

                // Obtener Nombre y Apellido
                getline(ss, dato, ',');
                string nombreApellido = dato;

                // Crear usuario y agregarlo a la lista
                Usuario usuario(dni, nombreApellido);
                usuarios.push_back(usuario);
            }

            archivo.close();
            cout << "Datos de usuarios cargados desde " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }
};