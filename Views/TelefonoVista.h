#include <iostream>
#include "../Controllers/UsuarioController.h"
#include "../Controllers/TelefonoController.h"
#include "../Controllers/UsuarioTelefonoController.h"

using namespace std;

UsuarioController usuarios;
TelefonoController telefonos;
UsuarioTelefonoController control;


void mostrarTitular(const unsigned int numero) {
	usuarios.cargarUsuariosDesdeArchivo();
	telefonos.cargarTelefonosDesdeArchivo();
	control.cargarNumeros(usuarios,telefonos);
	if(telefonos.isExist(numero)) {
		int dni = usuarios.buscarDniPorTelefono(numero);
		Usuario& usuario = usuarios.buscarUsuario(dni);
		usuarios.mostrarUsuarios(usuario);
	} else {
		cout << "El numero no existe." << endl;
	}
}

void agregarTelefono(const Telefono& telefono) {
	usuarios.cargarUsuariosDesdeArchivo();
	telefonos.cargarTelefonosDesdeArchivo();
	control.cargarNumeros(usuarios,telefonos);
	if(!telefonos.isExist(telefono.getNumero())) {
		telefonos.guardarTelefonoEnArchivo(telefono);
		control.guardarNuevoNumero(telefono);
	} else {
		cout << "El numero ya existe" << endl;
	}
}

void buscarOperador(const unsigned int numero) {
	usuarios.cargarUsuariosDesdeArchivo();
	telefonos.cargarTelefonosDesdeArchivo();
	control.cargarNumeros(usuarios,telefonos);
	if(telefonos.isExist(numero)){
		telefonos.mostrarTelefono(telefonos.buscarTelefono(numero));
	} else {
		cout << "No existe el numero." << endl;
	}
}

void desactivarLinea(const unsigned int numero) {
	if(telefonos.isExist(numero)) {
		if(telefonos.buscarTelefono(numero).getActivo()) {
			telefonos.buscarTelefono(numero).setActivo(false);
			cout << "El numero se ha desactivado" << endl;
		} else {
			cout << "El numero ya esta desactivado" << endl;
		}
	} else {
		cout << "El numero no existe" << endl;
	}
}

void activarLinea(const unsigned int numero) {
	if(telefonos.isExist(numero)) {
		if(!telefonos.buscarTelefono(numero).getActivo()) {
			telefonos.buscarTelefono(numero).setActivo(true);
			cout << "El numero se ha activado." << endl;
		} else {
			cout << "El numero ya esta activo" << endl;
		}
	} else {
		cout << "El numero no existe" << endl;
	}
}


