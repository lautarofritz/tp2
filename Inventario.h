#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <map>
#include <mutex>
#include <condition_variable>
#include "Receta.h"

class Inventario {
	private:
		std::map<char, int> inventario;
		std::mutex m;
		std::condition_variable cv;
		bool cerrado;

		bool recetaCompleta(const Receta &receta);
		void restarRecursos(const Receta &receta);

	public:
		Inventario();
		void depositar(const char recurso);
		int obtener(const Receta &receta);
		void cerrar();
		void mostrarBalance();
};

#endif
