#pragma once
#include <string> 

class Menu
{
	std::string* _vstrOpciones;
	int _tamanio;
	bool _salir = false;

public:

	Menu(int cantItem);
	~Menu();

	void setItem(int indice, std::string texto);
	void dibujarMenu();
	int obtenerRespuesta();
};