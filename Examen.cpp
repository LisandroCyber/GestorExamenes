#include "Examen.h"

/// CONSTRUCTORES

Examen::Examen()
{
	_fecha = (0, 0, 0);
	_legajo = 0;
	_codMateria = 0;
	_calificacion = 0;
	_tipoExamen = '0';
}

Examen::Examen(Fecha fecha, int legajo, int codMateria,
	float calificacion, char tipoExamen) 
{
	_fecha = fecha;
	_legajo = legajo;
	_codMateria = codMateria;
	_calificacion = calificacion;
	_tipoExamen = tipoExamen;
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

