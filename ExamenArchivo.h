#pragma once
#include <string>
#include "Examen.h"

class ExamenArchivo
{
public:
	ExamenArchivo(std::string nombreArchivo = "Examenes.dat");
	void guardar(Examen examen);
	void leer(Examen examen[], int pos);
	int getCantRegistros();
	
private:
	std::string _nombreArchivo;
};

