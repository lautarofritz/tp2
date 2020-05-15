#include <unistd.h>
#include "Productor.h"

#define TIEMPO_DORMIR 6000

Productor::Productor(Inventario &inv, Receta receta, Fabrica &fab) :
	inv(inv), receta(receta), fabrica(fab) {}

void Productor::ejecutar(){
	int puntos;
	while(true){
		puntos = this->inv.obtener(receta);
		if(puntos == 0){
			fabrica.notificarProductor();
			return;
		}
		usleep(TIEMPO_DORMIR);
		inv.depositarPuntos(puntos);
		puntos = 0;
	}
}
