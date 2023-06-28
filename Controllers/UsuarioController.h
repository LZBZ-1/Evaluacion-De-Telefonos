#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
#include "../Library/List.h"
#include "../Models/Usuario.h"

using namespace std;

class UsuarioController {
private:
    List<Usuario> usuarios;

public:
    UsuarioController() = default;
    ~UsuarioController() = default;

    void agregarUsuario(Usuario usuario) {
        usuarios.push_back(usuario);
        guardarUsuarioEnArchivo(usuario);
    }

    void mostrarUsuarios(Usuario& usuario) {
        cout << "DNI: " << usuario.getDni() << endl;
        cout << "Nombre y Apellido: " << usuario.getNombreApellido() << endl;
        cout << "Sus lineas telefonicas son: " << endl;
        for(int i = 0; i < usuario.getNumeroTelefono().size(); i++) {
            cout << i+1 << ". " << usuario.getNumeroTelefono()[i] << endl;
        }
        cout << endl;
    }

    Usuario& buscarUsuario(const unsigned int dni) {
        for(int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i].getDni() == dni) {
                return usuarios[i];
            }
        }

        throw runtime_error("No se encontro un usuario con el DNI especificado");
    }

    int buscarDniPorTelefono(unsigned int numeroTelefono) {
        for (int i = 0; i < usuarios.size(); i++) {
            const List<unsigned int>& numeros = usuarios[i].getNumeroTelefono();
            for (int j = 0; j < numeros.size(); j++) {
                if (numeros[j] == numeroTelefono) {
                    return usuarios[i].getDni();
                }
            }
        }
        return -1; // Retornar -1 si no se encuentra el número de teléfono
    }

    void guardarUsuarioEnArchivo(const Usuario& usuario) {
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\usuario.csv";
        ofstream archivo(nombreArchivo, ios_base::app);
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
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\usuario.csv";
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Escribir encabezados de columna
            archivo << "dni,nombreApellido" << endl;

            // Escribir datos de usuarios
            for (int i = 0; i < usuarios.size(); i++) {
                archivo << usuarios[i].getDni() << "," << usuarios[i].getNombreApellido();
                archivo << endl;
            }

            archivo.close();
            cout << "Archivo CSV actualizado correctamente." << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }

    void cargarUsuariosDesdeArchivo() {
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\usuario.csv";
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
                getline(ss, dato, '\n');
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
