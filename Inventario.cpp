#include "Inventario.h"
#include <iostream>
#include <iterator>

Inventario::Inventario(){
	this->inventario['T'] = 0;
	this->inventario['M'] = 0;
	this->inventario['H'] = 0;
	this->inventario['C'] = 0;
	this->cerrado = false;
}

void Inventario::depositar(const char recurso){
	std::lock_guard<std::mutex> lock(m);
    this->inventario.at(recurso) += 1;
    //resetea un timer
    cv.notify_all();
}

void Inventario::cerrar(){
	std::lock_guard<std::mutex> lock(m);
	this->cerrado = true;
	cv.notify_all();
}

int Inventario::obtener(const Receta &receta){
	std::unique_lock<std::mutex> lock(m);
	while(!recetaCompleta(receta)){
		if(this->cerrado)
			return 0;
		this->cv.wait(lock);								//wait_for? y si pasaron muchos segundos se va 
	}
	restarRecursos(receta);
	return receta.getPuntos();
}

bool Inventario::recetaCompleta(const Receta &receta){
	bool completa = true;
	std::map<char, int> cantidades = receta.getCantidades();
	std::map<char, int>::iterator it = cantidades.begin();
	while(it != cantidades.end()){
		if(this->inventario.at(it->first) < it->second){
			completa = false;
			break;
		}
		it++;
	}
	return completa;
}

void Inventario::restarRecursos(const Receta &receta){
	std::map<char, int> cantidades = receta.getCantidades();
	std::map<char, int>::iterator it = cantidades.begin();
	while(it != cantidades.end()){
		this->inventario.at(it->first) -= it->second;
		it++;
	}
}

void Inventario::mostrarBalance(){
	std::cout << "Recursos restantes:" << std::endl;
	std::cout << "  - Trigo: " << inventario.at('T') << std::endl;
	std::cout << "  - Madera: " << inventario.at('M') << std::endl;
	std::cout << "  - Hierro: " << inventario.at('H') << std::endl;
	std::cout << "  - Carbon: " << inventario.at('C') << std::endl;
	std::cout << std::endl;
}
