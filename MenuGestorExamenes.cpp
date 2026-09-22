#include "MenuGestorExamenes.h"
#include <iostream>
#include "ExamenManager.h"

MenuGestorExamenes::MenuGestorExamenes() : Menu(3)
{
	setItem(1, "Cargar Examen");
	setItem(2, "Listar Examenes");
	setItem(3, "Buscar mejor nota");
}

void MenuGestorExamenes::run() {
    ExamenManager manager;
    int opcion;
    
    do {
        dibujarMenu();
        std::cout << std::endl << " Opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            manager.crearExamen();
            break;
        case 2:
            manager.listarTodos();
            break;
        case 3:
            manager.mostrarMejorNota();
            break;
        case 0:
            std::cout << " Saliendo...";
            break;
        default:
            std::cout << " Opcion invalida.";
        }
        
    } while (opcion != 0);
}
