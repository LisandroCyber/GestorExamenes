#include "Menu.h"
#include <string>
#include <iostream>

Menu::Menu(int cantItem) {
	_vstrOpciones = new std::string[cantItem];
	_tamanio = cantItem;
}

Menu::~Menu() {
	delete[] _vstrOpciones;
}

void Menu::setItem(int indice, std::string texto) {
	_vstrOpciones[indice - 1] = texto;
}

void Menu::dibujarMenu() {
	std::cout << std::endl << "  " << "------ MENU ------" << std::endl;

	for (int i = 0; i < _tamanio; i++) {
		std::cout << "  " << i + 1 << " - " << _vstrOpciones[i] << std::endl;
	}
	std::cout << "  " << "0 - Salir " << std::endl;
}

int Menu::obtenerRespuesta() {

	int opcion;

	do {
		std::cout << std::endl << "  " << " Opcion: ";
		std::cin >> opcion;

		if (opcion <0 || opcion > _tamanio) {
			std::cout << "  " << " Opcion Incorrecta..." << std::endl;
		}

	} while (opcion <0 || opcion > _tamanio);

	return opcion;
}