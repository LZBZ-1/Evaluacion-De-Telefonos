#include "../Library/List"
#include "../Models/Usuario"

class UsuarioController {
private:
    list<Usuario> usuarios;

public:
    void agregarUsuario(const Usuario& usuario) {
        usuarios.push_back(usuario);
    }

    void mostrarUsuarios(const auto& usuario) {
        cout << "DNI: " << usuario.getDni() << endl;
        cout << "Nombre y Apellido: " << usuario.getNombreApellido() << endl;
        cout << endl;
    }

    int buscarDniPorTelefono(unsigned int numeroTelefono) {
        for (const auto& usuario : usuarios) {
            const list<unsigned int>& numeros = usuario.getNumeroTelefono();
            for (const auto& numero : numeros) {
                if (numero == numeroTelefono) {
                    return usuario.getDni();
                }
            }
        }
        return -1; // Retornar -1 si no se encuentra el número de teléfono
    }
};