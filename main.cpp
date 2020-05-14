#include <iostream>
#include <cstring>
#include <fstream>
#include "Fabrica.h"

void factory(std::string tipo, std::string cant, std::vector<Thread*> v[]);

/*int main(){
	std::fstream fs;
	fs.open("culo.txt", std::ios::in);
	std::string tipo, cant;
	std::vector<int> trabajadores[6];
	while(std::getline(fs, tipo, '=')){
		std::getline(fs, cant);
		factory(tipo, cant, trabajadores);
	}
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < trabajadores[i].size(); j++)
			std::cout << trabajadores[i][j];
		std::cout << std::endl;
	}
	fs.close();

}

void factory(std::string tipo, std::string cant, std::vector<int> v[]){
	int pito = std::stoi(cant);
	for(int i = 0; i < pito; i++){
		if(tipo.compare("Agricultores") == 0){
			v[0].push_back(i);
		} else if (tipo.compare("Leniadores") == 0){
			v[1].push_back(i);
		} else if (tipo.compare("Mineros") == 0){
			v[2].push_back(i);
		} else if (tipo.compare("Cocineros") == 0){
			v[3].push_back(i);
		} else if (tipo.compare("Carpinteros") == 0){
			v[4].push_back(i);
		} else if (tipo.compare("Armeros") == 0){
			v[5].push_back(i);
		}
	}
}*/

/*int main(){
	std::fstream fs;
	fs.open("culo.txt", std::ios::in);
	std::string tipo, cant;
	std::vector<Thread*> trabajadores[6];
	while(std::getline(fs, tipo, '=')){
		std::getline(fs, cant);
		factory(tipo, cant, trabajadores);
	}
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < trabajadores[i].size(); j++)
			trabajadores[i][j]->start();
	}
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < trabajadores[i].size(); j++){
			trabajadores[i][j]->join();
			delete trabajadores[i][j];
		}
	}
	fs.close();

}

void factory(std::string tipo, std::string cant, std::vector<Thread*> v[]){
	int pito = std::stoi(cant);
	for(int i = 0; i < pito; i++){
		if(tipo.compare("Agricultores") == 0){
			v[0].push_back(new Recolector(ColaTrigo));
		} else if (tipo.compare("Leniadores") == 0){
			v[1].push_back(new Recolector(ColaMadera));
		} else if (tipo.compare("Mineros") == 0){
			v[2].push_back(new Recolector(ColaMineral));
		} else if (tipo.compare("Cocineros") == 0){
			v[3].push_back(new Pito('C'));
		} else if (tipo.compare("Carpinteros") == 0){
			v[4].push_back(new Pito('c'));
		} else if (tipo.compare("Armeros") == 0){
			v[5].push_back(new Pito('a'));
		}
	}
}*/

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
	parsearTrabajo(fsTrabajo, fabrica);
	fsTrabajo.close();

	fabrica.empezar();

	fsMapa.open(mapa, std::ios::in);
	parsearMapa(fsMapa, fabrica);
	fsMapa.close();

	fabrica.cerrar();
	fabrica.mostrarBalance();

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