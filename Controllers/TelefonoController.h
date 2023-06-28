#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include "../Library/List.h"
#include "../Models/Telefono.h"

using namespace std;

class TelefonoController {
private:
    List<Telefono> telefonos;

public:
    TelefonoController() = default;
    ~TelefonoController() = default;

    void agregarTelefono(const Telefono& telefono) {
        telefonos.push_back(telefono);
        guardarTelefonoEnArchivo(telefono);
    }

    void mostrarTelefono(const Telefono& telefono) {
        cout << "Número: " << telefono.getNumero() << endl;
        cout << "Activo: " << (telefono.getActivo() ? "Sí" : "No") << endl;
        cout << "Operadora: " << telefono.getOperadora() << endl;
        cout << "Tipo de Plan: " << telefono.getTipoPlan() << endl;
        cout << endl;
    }

    List<Telefono> buscarTelefonosPorDni(int dni) {
        List<Telefono> telefonosEncontrados;
        for (const auto& telefono : telefonos) {
            if (telefono.getDniUsuario() == dni) {
                telefonosEncontrados.push_back(telefono);
            }
        }
        return telefonosEncontrados;
    }

    Telefono& buscarTelefono(const unsigned int numero) {
        for(int i = 0; i < telefonos.size(); i++) {
            if(telefonos[i].getNumero == numero) {
                return telefono[i];
            }
        }

        throw runtime_error("No se encontro el telefono solicitado");
    }

    void guardarTelefonoEnArchivo(const Telefono& telefono) {
        const string nombreArchivo = "../Data/telefono.csv";
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Escribir datos del teléfono
            archivo << telefono.getNumero() << "," << telefono.getActivo() << ","
                     << telefono.getOperadora() << "," << telefono.getTipoPlan() << endl;

            archivo.close();
            cout << "Datos del teléfono guardados en " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }

    void actualizarArchivoCSV() {
        const string nombreArchivo = "../Data/telefono.csv";
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Escribir encabezados de columna
            archivo << "numero,activo,operadora,tipoPlan" << endl;

            // Escribir datos de teléfonos
            for (const auto& telefono : telefonos) {
                archivo << telefono.getNumero() << "," << telefono.getActivo() << ","
                        << telefono.getOperadora() << "," << telefono.getTipoPlan() << endl;
            }

            archivo.close();
            cout << "Archivo CSV actualizado correctamente." << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }

    void cargarTelefonosDesdeArchivo() {
        const string nombreArchivo = "../Data/telefono.csv";
        telefonos.clear();

        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Leer encabezados de columna
            string encabezados;
            getline(archivo, encabezados);

            // Leer datos de teléfonos
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string dato;

                // Obtener Número
                getline(ss, dato, ',');
                unsigned int numero = stoi(dato);

                // Obtener Activo
                getline(ss, dato, ',');
                bool activo = (dato == "1");

                // Obtener Operadora
                getline(ss, dato, ',');
                string operadora = dato;

                // Obtener Tipo de Plan
                getline(ss, dato, ',');
                string tipoPlan = dato;

                // Crear teléfono y agregarlo a la lista
                Telefono telefono(numero, activo, operadora, tipoPlan);
                telefonos.push_back(telefono);
            }

            archivo.close();
            cout << "Datos de teléfonos cargados desde " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }
};