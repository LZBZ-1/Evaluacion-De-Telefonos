#include <iostream>
#include "../Controllers/UsuarioController.h"
#include "../Controllers/TelefonoController.h"
#include "../Controllers/UsuarioTelefonoController.h"

using namespace std;

void agregarUsuario(const Usuario& usuario) {
	usuarios.cargarUsuariosDesdeArchivo();
	telefonos.cargarTelefonosDesdeArchivo();
	control.cargarNumeros(usuarios,telefonos);
	if (usuarios.isExist(usuario.getDni())){
		cout << "El usuario ya existe" << endl;
	} else {
		usuarios.guardarUsuarioEnArchivo(usuario);
	}
}

void mostrarLineas(const unsigned int dni) {
	usuarios.cargarUsuariosDesdeArchivo();
	telefonos.cargarTelefonosDesdeArchivo();
	control.cargarNumeros(usuarios,telefonos);
	if(usuarios.isExist(dni)) {
		Usuario& usuario = usuarios.buscarUsuario(dni);
		List<unsigned int>& telefonosEncontrado = usuario.getNumeroTelefono();
		for(int i = 0; i < telefonosEncontrado.size(); i++ ) {
			telefonos.mostrarTelefono(telefonos.buscarTelefono(telefonosEncontrado[i]));
		}	
	} else {
		cout << "No existe el usuario" << endl;
	}
}




