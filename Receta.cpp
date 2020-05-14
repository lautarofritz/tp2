#include "Receta.h"

Receta::Receta(char recurso1, int cant1, char recurso2, int cant2, int puntos){
	this->puntos = puntos;
	this->receta[recurso1] = cant1;
	this->receta[recurso2] = cant2;
}

/*bool Receta::recetaCompleta(const std::map<char, int> &inventario){
	bool completa = true;
	std::map<char, int>::iterator itInventario = inventario.begin();
	std::map<char, int>::iterator itReceta = this->receta.begin();
	while(itReceta != this->receta.end()){
		if(itReceta->second == 0){
			itReceta++;
			itInventario++;
			continue;
		}
		if(itInventario->second < itReceta->second){
			completa = false;
			break;
		}
		itReceta++;
		itInventario++;
	}
	return completa;
}

std::map<char, int> Receta::getCantidades(){
	std::map<char, int>::iterator itReceta = this->receta.begin();
	std::map<char, int> cantidades;
	while(itReceta != this->receta.end()){
		if(itReceta->second == 0)
			itReceta++;

		cantidades.insert({itReceta->first, itReceta->second});
	}
	return cantidades;
}*/

std::map<char, int> Receta::getCantidades() const {
	return this->receta;
}

int Receta::getPuntos() const {
	return puntos;
}
