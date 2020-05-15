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
		int puntos;

		//chequea si se tienen los materiales necesarios
		//para producir puntos de beneficio
		bool recetaCompleta(const Receta &receta);
		void restarRecursos(const Receta &receta);

	public:
		Inventario();

		//recibe un recurso del recolector, el cual coloca en 
		//el inventario según su tipo
		//al ocurrir esto, notifica a los productores que 
		//esten esperando
		void depositar(const char recurso);

		//comprueba si se tienen los materiales necesarios
		//según la receta recibida por parámetro
		//si los posee, resta las cantidades solicitadas
		//y retorna el número de puntos correspondiente
		//si no los posee, el productor quedará esperando
		//si además el inventario está cerrado, retorna 0, marcando
		//que no ingresarán más recursos
		int obtener(const Receta &receta);
		void depositarPuntos(const int puntos);

		//marca el cierre del inventario
		//ocurre cuando ya no quedan recolectores activos
		//a partir de este momento, ningún productor que esté
		//esperando podrá completar su receta, ya que no ingresarán
		//más materias primas al inventario
		void cerrar();
		void mostrarBalance();
};

#endif
