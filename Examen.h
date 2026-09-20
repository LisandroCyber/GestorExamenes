#pragma once
#include "Fecha.h"
class Examen
{
public:
	Examen();
	Examen(Fecha fecha, int legajo, int codMateria,
		float calificacion, char tipoExamen);

	Fecha getFecha();
	int getLegajo();
	int getCodMateria();
	float getCalifiacion();
	char getTipoExamen();

private:
	Fecha _fecha;
	int _legajo;
	int _codMateria;
	float _calificacion; // entre 0 y 10
	char _tipoExamen; // ('P' - Parcial o 'F' - Final)

	void setFecha(Fecha fecha);
	void setLegajo(int legajo);
	void setCodMateria(int codMateria);
	void setCalificacion(float calificacion);
	void setTipoExamen(char tipoExamen);

};

