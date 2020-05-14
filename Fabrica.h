#ifndef FABRICA_H
#define FABRICA_H

#include <vector>
#include <cstring>
#include "Thread.h"
#include "ColaBloqueante.h"
#include "Inventario.h"

class Fabrica {
	private:
		std::vector<Thread*> trabajadores[6];
		ColaBloqueante colaTrigo;
		ColaBloqueante colaMadera;
		ColaBloqueante colaMinerales;
		Inventario inv;
		std::condition_variable cvRecolector;
		std::condition_variable cvProductor;
		std::mutex mutex;
		int cantRecolectores;
		int cantProductores;

	public:
		Fabrica();
		void asignarTrabajo(std::string tipo, int cantidad);
		void asignarRecurso(char recurso);
		void empezar();
		void cerrar();
		void mostrarBalance();
		~Fabrica();

};

#endif
