#include "#include ../Library/List"

class TelefonoController {
private:
    List<Telefono> telefonos;

public:
    void agregarTelefono(const Telefono& telefono) {
        telefonos.push_back(telefono);
    }

    void mostrarTelefono(const Telefono& telefono) {
        cout << "Número: " << telefono.getNumero() << endl;
        cout << "Activo: " << (telefono.getActivo() ? "Sí" : "No") << endl;
        cout << "Operadora: " << telefono.getOperadora() << endl;
        cout << "Tipo de Plan: " << telefono.getTipoPlan() << endl;
        cout << endl;
    }
};