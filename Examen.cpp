#include "Examen.h"
#include <iostream>
#include <iomanip> // para mostrar los examenes listados segun el formato sugerido

/// CTOR
Examen::Examen()
{
	_fecha = (0, 0, 0);
	_legajo = 0;
	_codMateria = 0;
	_calificacion = 0;
	_tipoExamen = '0';
}

// No valido los datos aca porque no se usan los set, sino el metodo crearExamen del manager.
// de ser necesario usar los set, habria que validar las entradas.

Examen::Examen(Fecha fecha, int legajo, int codMateria,
	float calificacion, char tipoExamen) 
{
	_fecha = fecha;
	_legajo = legajo;
	_codMateria = codMateria;
	_calificacion = calificacion;
	_tipoExamen = tipoExamen;
}

/// aca uso <iomanip> para mostrar los datos con el formato sugerido

void Examen::mostrarEnLista() {
	std::cout << std::left
		<< std::setw(10) << _legajo
		<< std::setw(15) << _codMateria
		<< std::setw(15) << _fecha.toString()
		<< std::setw(15) << (_tipoExamen == 'P' || _tipoExamen == 'p' ? "PARCIAL" : "FINAL")
		<< std::right << std::setw(12)
		<< std::fixed << std::setprecision(2) << _calificacion
		<< std::endl;
}

/// SETTERS

void Examen::setFecha(Fecha fecha)
{
	_fecha.cargar();
}

void Examen::setLegajo(int legajo)
{
	_legajo = legajo;
}

void Examen::setCodMateria(int codMateria)
{
	_codMateria = codMateria;
}

void Examen::setCalificacion(float calificacion)
{
	_calificacion = calificacion;
}

void Examen::setTipoExamen(char tipoExamen)
{
	_tipoExamen = tipoExamen;
}

/// GETTERS

Fecha Examen::getFecha() {
	return _fecha;
}

int Examen::getLegajo() {
	return _legajo;
}

int Examen::getCodMateria() {
	return _codMateria;
}

float Examen::getCalifiacion() {
	return _calificacion;
}

char Examen::getTipoExamen() {
	return _tipoExamen;
}

