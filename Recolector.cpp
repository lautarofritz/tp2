#include <unistd.h>
#include "Recolector.h"

#define TIEMPO_DORMIR 5000

Recolector::Recolector(ColaBloqueante &cola, Inventario &inv, Fabrica &fab) :
	cola(cola), inv(inv), fabrica(fab) {}

void Recolector::ejecutar(){
	char recurso;
	while(true){
		recurso = this->cola.obtener();
		if(recurso == '\0'){
			fabrica.notificarRecolector();
			return;
		}
		usleep(TIEMPO_DORMIR);
		this->inv.depositar(recurso);
	}
}
