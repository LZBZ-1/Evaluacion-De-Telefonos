#pragma once
#include <iostream>
#include <fstream>
#include "../Library/List.h"
#include "../Models/Telefono.h"
#include "../Models/Usuario.h"
#include "UsuarioController.h"
#include "TelefonoController.h"

using namspace std;

class UsuarioTelefonoController {
public:
	static void cargarNumeros(UsuarioController& usuarios, TelefonoController& telefonos) {
		const string nombreArchivo = "../Data/usuarioTelefono.csv";
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
                getline(ss, dato, '');
                unsigned int numero = dato;

                // Anadir un Numero al Usuario
                Usuario& usuarioEncontrado = buscarUsuario(dni);
                usuarioEncontrado.agregarNumeroTelefono(numero);

                // Anadir un Usuario al Numero
                Telefono& telefonoEncontrado = buscarTelefono(numero);
                telefonoEncontrado.setDniUsuario(dni);

            }

            archivo.close();
            cout << "Datos de usuarios cargados desde " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
	}
};