#pragma once
#include <string>
#include "Examen.h"
#include "ExamenArchivo.h"

class ExamenManager
{
public:
	ExamenManager(const std::string& nombreArchivo = "Examenes.dat");
	void crearExamen();
	void listarTodos();
	void mostrarMejorNota();

private:
	ExamenArchivo _archivoExamen;
	std::string _nombreArchivo;

};
