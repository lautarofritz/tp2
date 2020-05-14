#include <unistd.h>
#include <iostream>
#include "Recolector.h"

#define TIEMPO_DORMIR 5000

Recolector::Recolector(ColaBloqueante &cola, Inventario &inv, std::condition_variable &cv, int &d) : cola(cola), inv(inv), cv(cv), d(d) {}

void Recolector::run(){
	char recurso;
	while(true){
		recurso = this->cola.obtener();
		if(recurso == '\0'){
			std::unique_lock<std::mutex> lock(m);
			d--;
			cv.notify_all();
			lock.unlock();
			return;
		}
		usleep(TIEMPO_DORMIR);
		this->inv.depositar(recurso);
	}
}