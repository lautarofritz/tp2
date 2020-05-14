#ifndef RECETA_H
#define RECETA_H

#include <map>

class Receta {
	private:
		std::map<char, int> receta;
		int puntos;

	public:
		Receta(char recurso1, int cant1, char recurso2, int cant2, int puntos);
		std::map<char, int> getCantidades() const;
		int getPuntos() const;
};

#endif
