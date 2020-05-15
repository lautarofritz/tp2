#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include "Fabrica.h"

class Recolector : public Thread {
	private:
		ColaBloqueante &cola;
		Inventario &inv;
		Fabrica &fabrica;

	public:
		Recolector(ColaBloqueante &cola, Inventario &inv, Fabrica &fabrica);
		virtual void ejecutar() override;
};

#endif
