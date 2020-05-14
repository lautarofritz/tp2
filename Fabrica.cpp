#include <iostream>
#include "Fabrica.h"
#include "Recolector.h"
#include "Productor.h"
#include "Receta.h"

#define TIPOS_DE_TRABAJADORES 6

Fabrica::Fabrica() : colaTrigo(), colaMadera(), colaMinerales(), inv() {
	this->cantRecolectores = 0;
	this->cantProductores = 0;
}

void Fabrica::asignarTrabajo(std::string tipo, int cantidad){
	for(int i = 0; i < cantidad; i++){
		if(tipo == "Agricultores"){
			trabajadores[0].push_back(new Recolector(colaTrigo, inv, cvRecolector, cantRecolectores));
		} else if (tipo == "Leniadores"){
			trabajadores[1].push_back(new Recolector(colaMadera, inv, cvRecolector, cantRecolectores));
		} else if (tipo == "Mineros"){
			trabajadores[2].push_back(new Recolector(colaMinerales, inv, cvRecolector, cantRecolectores));
		} else if (tipo == "Cocineros"){
			Receta receta('T', 2, 'C', 1, 5);
			trabajadores[3].push_back(new Productor(inv, receta, cvProductor));
		} else if (tipo == "Carpinteros"){
			Receta receta('M', 3, 'H', 1, 2);
			trabajadores[4].push_back(new Productor(inv, receta, cvProductor));
		} else if (tipo == "Armeros"){
			Receta receta('H', 2, 'C', 2, 3);
			trabajadores[5].push_back(new Productor(inv, receta, cvProductor));
		}
	}
} //quizas deba almacenar cant de recolectores y productores activos

void Fabrica::asignarRecurso(const char recurso){
	switch(recurso){
		case 'T':
			colaTrigo.insertar(recurso);
		break;
		case 'M':
			colaMadera.insertar(recurso);
		break;
		default:
			colaMinerales.insertar(recurso);
		break;
	}
}

void Fabrica::empezar(){
	for(int i = 0; i < TIPOS_DE_TRABAJADORES; i++){
		for(unsigned int j = 0; j < trabajadores[i].size(); j++){
			trabajadores[i][j]->start();
			if(i < 3)
				cantRecolectores++;
			else
				cantProductores++;
		}
	}
}

void Fabrica::cerrar(){
	std::unique_lock<std::mutex> lock(mutex);
	this->colaTrigo.cerrar();
	this->colaMadera.cerrar();
	this->colaMinerales.cerrar();
	/*while(!colaTrigo.vacia() || !colaMadera.vacia() || !colaMinerales.vacia()){
		
    }*/
    std::cout << "colas cerradas\n";
    while(cantRecolectores > 0){
    	cvRecolector.wait(lock);
		std::cout << cantRecolectores << " ";
    }
    std::cout << "inventario cerrado\n";
	this->inv.cerrar();
	while(cantProductores > 0){
    	cvProductor.wait(lock);
		cantProductores--;
		std::cout << cantProductores << " ";
    }
}

void Fabrica::mostrarBalance(){
	inv.mostrarBalance();
}

Fabrica::~Fabrica(){
	for(int i = 0; i < TIPOS_DE_TRABAJADORES; i++){
		for(unsigned int j = 0; j < trabajadores[i].size(); j++){
			trabajadores[i][j]->join();
			delete trabajadores[i][j];
		}
	}
}
