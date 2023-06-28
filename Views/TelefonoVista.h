#include <iostream>
#include "../Controllers/UsuarioController.h"
#include "../Controllers/TelefonoController.h"
#include "../Controllers/UsuarioTelefonoController.h"

using namespace std;

void mostrarTitular(const unsigned int numero) {
	UsuarioController usuarios;
	usuarios.cargarUsuariosDesdeArchivo();
	TelefonoController telefonos;
	telefonos.cargarTelefonosDesdeArchivo();
	UsuarioTelefonoController control;
	control.cargarNumeros(usuarios,telefonos);
	int dni = usuarios.buscarDniPorTelefono(numero);
	Usuario& usuario = usuarios.buscarUsuario(dni);
	usuarios.mostrarUsuarios(usuario);
}