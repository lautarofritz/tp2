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
		void insertar(char recurso);
		char obtener();
		void cerrar();
		bool vacia();
		//~ColaBloqueante();
};

#endif
