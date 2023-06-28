#include "../Library/List"

using namespace std;

class Telefono {
private:
    unsigned int numero;
    bool activo;
    string operadora;
    string tipoPlan;
    int dni_Usuario;

public:
    // Constructor por defecto
    Telefono() = default;

    // Constructor con todos los datos
    Telefono(unsigned int numero, bool activo, const string& operadora, const string& tipoPlan, int dni_Usuario) :
        numero(numero),
        activo(activo),
        operadora(operadora),
        tipoPlan(tipoPlan),
        dni_Usuario(dni_Usuario) {}

    // Constructor sin el DNI del usuario
    Telefono(unsigned int numero, bool activo, const string& operadora, const string& tipoPlan) :
        numero(numero),
        activo(activo),
        operadora(operadora),
        tipoPlan(tipoPlan) {}

    // Destructor
    ~Telefono() = default;

    // Getters y Setters
    unsigned int getNumero() const {
        return numero;
    }

    void setNumero(unsigned int numero) {
        this->numero = numero;
    }

    bool getActivo() const {
        return activo;
    }

    void setActivo(bool activo) {
        this->activo = activo;
    }

    string getOperadora() const {
        return operadora;
    }

    void setOperadora(const string& operadora) {
        this->operadora = operadora;
    }

    string getTipoPlan() const {
        return tipoPlan;
    }

    void setTipoPlan(const string& tipoPlan) {
        this->tipoPlan = tipoPlan;
    }

    int getDniUsuario() const {
        return dni_Usuario;
    }

    void setDniUsuario(int dni_Usuario) {
        this->dni_Usuario = dni_Usuario;
    }
};