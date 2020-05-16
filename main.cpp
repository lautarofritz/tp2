#include <iostream>
#include <string>
#include <fstream>
#include "Fabrica.h"

void parsearTrabajo(std::fstream &fsTrabajo, Fabrica &fabrica);

void parsearMapa(std::fstream &fsMapa, Fabrica &fabrica);

int main(int argc, char *argv[]){
	if(argc != 3){
		std::cout << "Modo de uso: ./tp <trabajadores> <mapa>" << std::endl;
		return 1;
	}
	std::string trabajadores = argv[1];
	std::string mapa = argv[2];
	std::fstream fsTrabajo, fsMapa;
	Fabrica fabrica;

	fsTrabajo.open(trabajadores, std::ios::in);
	if(!fsTrabajo)
		return 1;
	parsearTrabajo(fsTrabajo, fabrica);
	fsTrabajo.close();

	fabrica.empezar();

	fsMapa.open(mapa, std::ios::in);
	if(!fsMapa)
		return 1;
	parsearMapa(fsMapa, fabrica);
	fsMapa.close();

	fabrica.cerrar();

	return 0;
}

void parsearTrabajo(std::fstream &fsTrabajo, Fabrica &fabrica){
	std::string tipo, cant;
	int cantidad;
	while(std::getline(fsTrabajo, tipo, '=')){
		std::getline(fsTrabajo, cant);
		cantidad = std::stoi(cant);
		fabrica.asignarTrabajo(tipo, cantidad);
	}
}

void parsearMapa(std::fstream &fsMapa, Fabrica &fabrica){
	char recurso;
	while(fsMapa.get(recurso)){
		if (recurso == '\n')
			continue;
		fabrica.asignarRecurso(recurso);
	}
}
