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
};