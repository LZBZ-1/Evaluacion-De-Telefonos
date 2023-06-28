#pragma once

#include <iostream>
#include <fstream>
#include <string>
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

    void agregarTelefono(Telefono& telefono) {
        telefonos.push_back(telefono);
        guardarTelefonoEnArchivo(telefono);
    }

    bool isExist(int numero) {
        for(int i = 0; i < telefonos.size(); i++) {
            if(numero == telefonos[i].getNumero()) {
                return true;
            }
        }

        return false;
    }

    void mostrarTelefono(const Telefono& telefono) {
        cout << "Numero: " << telefono.getNumero() << endl;
        cout << "Activo: " << (telefono.getActivo() ? "Si" : "No") << endl;
        cout << "Operadora: " << telefono.getOperadora() << endl;
        cout << "Tipo de Plan: " << telefono.getTipoPlan() << endl;
        cout << endl;
    }

    List<Telefono> buscarTelefonosPorDni(int dni) {
        List<Telefono> telefonosEncontrados;
        for (int i = 0; i < telefonos.size(); i++) {
            if (telefonos[i].getDniUsuario() == dni) {
                telefonosEncontrados.push_back(telefonos[i]);
            }
        }
        return telefonosEncontrados;
    }

    Telefono& buscarTelefono(const unsigned int numero) {
        for(int i = 0; i < telefonos.size(); i++) {
            if(telefonos[i].getNumero() == numero) {
                return telefonos[i];
            }
        }

        throw runtime_error("No se encontro el telefono solicitado");
    }

    void guardarTelefonoEnArchivo(const Telefono& telefono) {
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\telefono.csv";
        ofstream archivo(nombreArchivo, ios_base::app);
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
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\telefono.csv";
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            // Escribir encabezados de columna
            archivo << "numero,activo,operadora,tipoPlan" << endl;

            // Escribir datos de teléfonos
            for (int i = 0; i < telefonos.size(); i++) {
                archivo << telefonos[i].getNumero() << "," << telefonos[i].getActivo() << ","
                        << telefonos[i].getOperadora() << "," << telefonos[i].getTipoPlan() << endl;
            }

            archivo.close();
            cout << "Archivo CSV actualizado correctamente." << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }

    void cargarTelefonosDesdeArchivo() {
        const string nombreArchivo = "C:\\Users\\jalb2\\OneDrive\\Documentos\\GitHub\\Evaluacion-De-Telefonos\\Data\\telefono.csv";
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
                bool activo = (dato == "true" || dato == "1");

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
            cout << "Datos de telefonos cargados desde " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo " << nombreArchivo << endl;
        }
    }
};
