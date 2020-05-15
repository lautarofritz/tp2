#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "Fabrica.h"

class Productor : public Thread {
	private:
		Inventario &inv;
		Receta receta;
		Fabrica &fabrica;

	public:
		Productor(Inventario &inv, Receta receta, Fabrica &fabrica);
		virtual void ejecutar() override;
};

#endif
