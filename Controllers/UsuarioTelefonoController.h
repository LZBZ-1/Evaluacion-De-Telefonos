#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../Library/List.h"
#include "../Models/Telefono.h"
#include "../Models/Usuario.h"
#include "UsuarioController.h"
#include "TelefonoController.h"

using namespace std;

class UsuarioTelefonoController {
public:
	void cargarNumeros(UsuarioController& usuarios, TelefonoController& telefonos) {
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\usuarioTelefono.csv";
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

                // Obtener Numero
                getline(ss, dato, '\n');
                unsigned int numero = stoi(dato);

                // Anadir un Numero al Usuario
                Usuario& usuarioEncontrado = usuarios.buscarUsuario(dni);
                usuarioEncontrado.agregarNumeroTelefono(numero);

                // Anadir un Usuario al Numero
                Telefono& telefonoEncontrado = telefonos.buscarTelefono(numero);
                telefonoEncontrado.setDniUsuario(dni);

            }

            archivo.close();
            cout << "Datos de control cargados desde " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
	}
};
