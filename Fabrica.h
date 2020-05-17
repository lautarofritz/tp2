#ifndef FABRICA_H
#define FABRICA_H

#include <vector>
#include <string>
#include "Thread.h"
#include "ColaBloqueante.h"
#include "Inventario.h"

#define TIPOS_DE_TRABAJADORES 6

class Fabrica {
	private:
		std::vector<Thread*> trabajadores[TIPOS_DE_TRABAJADORES];
		ColaBloqueante colaTrigo;
		ColaBloqueante colaMadera;
		ColaBloqueante colaMinerales;
		Inventario inv;
		std::condition_variable cv;
		std::mutex mutex;
		int cantTrabajadores;
		int cantProductores;

	public:
		Fabrica();

		//agrega "cantidad" trabajadores de determinado tipo 
		//al vector de trabajo según lo leído del archivo
		//trabajadores.cfg
		void asignarTrabajo(const std::string tipo, const int cantidad);

		//recorre el vector de trabajo, comenzando la ejecución
		//de cada trabajador
		void empezar();
		void asignarRecurso(const char recurso);

		//primero cierra las colas y queda esperando
		//el retorno de todos los recolectores
		//una vez sucedido esto, procede a cerrar el inventario
		//y aguarda el retorno de los productores
		void cerrar();

		//notifica a la Fábrica del fin del ciclo de trabajo
		//de algún trabajador
		void notificar();
		~Fabrica();
};

#endif
