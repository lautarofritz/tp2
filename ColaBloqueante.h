#ifndef COLA_BLOQUEANTE_H
#define COLA_BLOQUEANTE_H

#include <queue>
#include <mutex>
#include <condition_variable>

class ColaBloqueante {
	private:
		std::queue<char> cola;
		std::mutex m;
		std::condition_variable cv;
		bool cerrada;

	public:
		ColaBloqueante();

		//agrega un recurso a la cola y notifica
		//a los recolectores que estén esperando
		void insertar(const char recurso);

		//si la cola no está vacía, devuelve uno de los recursos
		//si la cola está vacía, los recolectores quedan esperando
		//si además está cerrada, devuelve '\0', marcando
		//que no ingresarán más recursos
		char obtener();

		//marca el cierre de la cola
		//a partir de este instante, no ingresarán más recursos a la misma
		//y notifica a los recolectores que estén esperando
		void cerrar();
};

#endif
