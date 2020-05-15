#include <map>
#include "Receta.h"

Receta::Receta(char recurso1, int cant1, char recurso2, int cant2, int puntos){
	this->puntos = puntos;
	this->receta[recurso1] = cant1;
	this->receta[recurso2] = cant2;
}

std::map<char, int> Receta::getCantidades() const {
	return this->receta;
}

int Receta::getPuntos() const {
	return puntos;
}
