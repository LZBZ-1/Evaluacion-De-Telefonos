#pragma once
#include "../Library/List.h"
#include <memory>

using namespace std;

class Usuario {
private:
    unsigned int dni;
    string nombreApellido;
    List<unsigned int> numeroTelefono;

public:
    // Constructor por defecto
    Usuario() = default;
    // Destructor
    ~Usuario() = default;

    // Constructor con todos los datos
    Usuario(unsigned int dni, const string& nombreApellido, List<unsigned int>& numeroTelefono) {
            this->dni = dni;
            this->nombreApellido = nombreApellido;
            this->numeroTelefono = std::move(numeroTelefono);
        }

    // Constructor sin números de teléfono
    Usuario(unsigned int dni, const string& nombreApellido) :
        dni(dni),
        nombreApellido(nombreApellido) {}

    // Getters y Setters
    unsigned int getDni() const {
        return dni;
    }

    void setDni(unsigned int dni) {
        this->dni = dni;
    }

    string getNombreApellido() const {
        return nombreApellido;
    }

    void setNombreApellido(const string& nombreApellido) {
        this->nombreApellido = nombreApellido;
    }

    List<unsigned int>& getNumeroTelefono() {
        return numeroTelefono;
    }

    void agregarNumeroTelefono(unsigned int numero) {
        numeroTelefono.push_back(numero);
    }
};