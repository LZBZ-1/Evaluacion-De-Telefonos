#include "../Library/List"

using namespace std;

class Usuario {
private:
    unsigned int dni;
    string nombreApellido;
    List<unsigned int> numeroTelefono;

public:
    // Constructor por defecto
    Usuario() = default;

    // Constructor con todos los datos
    Usuario(unsigned int dni, const string& nombreApellido, const List<unsigned int>& numeroTelefono) :
        dni(dni),
        nombreApellido(nombreApellido),
        numeroTelefono(numeroTelefono) {}

    // Constructor sin números de teléfono
    Usuario(unsigned int dni, const string& nombreApellido) :
        dni(dni),
        nombreApellido(nombreApellido) {}

    // Destructor
    ~Usuario() = default;

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

    List<unsigned int> getNumeroTelefono() const {
        return numeroTelefono;
    }

    void agregarNumeroTelefono(unsigned int numero) {
        numeroTelefono.push_back(numero);
    }
};