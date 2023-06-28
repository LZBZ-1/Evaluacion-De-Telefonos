#include <iostream>
#include "../Controllers/UsuarioController.h"
#include "../Controllers/TelefonoController.h"
#include "../Controllers/UsuarioTelefonoController.h"

using namespace std;

class PersonaVista {
private:
	UsuarioController usuarios;
	TelefonoController telefonos;
	UsuarioTelefonoController control;
public:
	PersonaVista(UsuarioController& usuarios, TelefonoController& telefonos, UsuarioTelefonoController& control) {
		this->usuarios = usuarios;
		this->telefonos = telefonos;
		this->control = control;
	}

	void agregarUsuario(const Usuario& usuario) {
		usuarios.isExist(usuario.getDni()) {
			cout << "El usuario ya existe" << endl;
		} else {
			usuarios.guardarUsuarioEnArchivo(usuario);
		}
	}

	void mostrarLineas(const unsigned int dni) {
		Usuario& usuario = usuarios.buscarUsuario(dni);	
	}
};
