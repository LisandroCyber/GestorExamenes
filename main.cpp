#include <iostream>
#include "ExamenManager.h"

int main()
{
    ExamenManager manager("Examenes.dat");
    int opcion = -1;

    while (opcion != 0)
    {
        std::cout << "\nMENU PRINCIPAL\n";
        std::cout << "----------------------------\n";
        std::cout << "1 - CARGAR EXAMEN\n";
        std::cout << "2 - LISTAR EXAMENES\n";
        std::cout << "3 - BUSCAR MEJOR NOTA\n";
        std::cout << "----------------------------\n";
        std::cout << "0 - SALIR\n";
        std::cout << "Ingrese opcion: ";
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
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida.\n";
        }
    }

    return 0;
}