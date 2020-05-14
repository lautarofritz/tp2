#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include "Thread.h"
#include "ColaBloqueante.h"
#include "Inventario.h"

class Recolector : public Thread {
	private:
		ColaBloqueante &cola;
		Inventario &inv;
		std::condition_variable &cv;
		int &d;
		std::mutex m;

	public:
		Recolector(ColaBloqueante &cola, Inventario &inv, std::condition_variable &cv, int &d);
		virtual void run();

};

#endif