#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "Thread.h"
#include "Receta.h"
#include "Inventario.h"

class Productor : public Thread {
	private:
		Inventario &inv;
		Receta receta;
		std::condition_variable &cv;

	public:
		Productor(Inventario &inv, Receta receta, std::condition_variable &cv);
		virtual void run();

};

#endif
