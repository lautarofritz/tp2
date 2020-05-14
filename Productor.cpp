#include <iostream>
#include <unistd.h>
#include "Productor.h"

#define TIEMPO_DORMIR 6000

Productor::Productor(Inventario &inv, Receta receta, std::condition_variable &cv) : inv(inv), receta(receta), cv(cv) {}

void Productor::run(){
	int puntos;
	while(true){
		puntos = this->inv.obtener(receta);
		usleep(TIEMPO_DORMIR);
		//this->centroDePuntos.depositar(puntos);
		if(puntos == 0){
			cv.notify_all();
			return;
		}
		//std::cout << puntos << std::endl;
		puntos = 0;
	}
}
