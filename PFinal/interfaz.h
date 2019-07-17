#include <iostream>
#include "lista.h"
#include "structs.h"

#ifndef INTERFAZ_H
#define INTERFAZ_H

using std::cout;
using std::cin;

class Interfaz{
public: 
	static void imprimirClientes(lista<cliente> clientes) {
		for (int i = 1; i <= clientes.get_tam(); ++i) {
			cliente auxiliar = clientes.buscar(i);			
			cout << auxiliar.nombre <<" - "<< auxiliar.apellido << "\n";
		}
	}
	
	static void imprimirPaseadores(lista<paseador> paseadores) {
		for (int i = 1; i <= paseadores.get_tam(); ++i) {
			paseador auxiliar = paseadores.buscar(i);			
			cout << auxiliar.nombre <<"-"<< auxiliar.apellido << "\n";
		}
	}
	
	
	static void imprimrPerros(lista<perro> perros) {
		for (int i = 1; i <= perros.get_tam(); ++i) {
			perro auxiliar = perros.buscar(i);			
			cout << auxiliar.nombre <<"-"<< auxiliar.raza << "\n";
		}
	}
	
	
	
		
	
};
#endif
