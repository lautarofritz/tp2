#include "ColaBloqueante.h"
#include <iostream>

ColaBloqueante::ColaBloqueante() : cerrada(false) {}

void ColaBloqueante::insertar(const char recurso){
	std::lock_guard<std::mutex> lock(m);
    this->cola.push(recurso);
    cv.notify_all();
}

char ColaBloqueante::obtener(){
	std::unique_lock<std::mutex> lock(m);
	while(this->cola.empty()){
		if(this->cerrada)
			return '\0';
		this->cv.wait(lock);
	}
	char recurso = this->cola.front();
	this->cola.pop();
	return recurso;
}

void ColaBloqueante::cerrar(){
	std::lock_guard<std::mutex> lock(m);
	this->cerrada = true;
	cv.notify_all();
}
