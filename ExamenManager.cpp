#define _CRT_SECURE_NO_WARNINGS  /// alternatica para no usar fopen_s

#include "ExamenManager.h"
#include "ExamenArchivo.h"
#include "Fecha.h"
#include <iostream>
#include <string>
#include <cstdio>

ExamenManager::ExamenManager(const std::string& nombreArchivo)
    : _nombreArchivo(nombreArchivo)
{
}

void ExamenManager::crearExamen()
{
    Fecha fecha;
    std::cout << "Cargar fecha del examen: \n";
    fecha.cargar();

    int legajo;
    std::cout << "Legajo: ";
    std::cin >> legajo;

    int codMateria;
    std::cout << "Codigo de materia: ";
    std::cin >> codMateria;

    float calificacion;
    std::cout << "Calificacion (0-10): ";
    std::cin >> calificacion;

    char tipo;
    std::cout << "Tipo de examen ('P' Parcial / 'F' Final): ";
    std::cin >> tipo;

    Examen examen(fecha, legajo, codMateria, calificacion, tipo);

    _archivoExamen.guardar(examen);
   

    std::cout << std::endl << "Examen guardado correctamente." << std::endl;
    

}

void ExamenManager::listarTodos()
{
    
    int cantidadRegistros = _archivoExamen.getCantRegistros();
    
    if (cantidadRegistros == 0) {
        std::cout << "No hay examenes guardados." << std::endl;
        return;
    }

    Examen* vecExamen = new Examen[cantidadRegistros];

    _archivoExamen.leer(vecExamen, cantidadRegistros);

    for (int i = 0; i < cantidadRegistros; i++) 
    {
        std::cout << std::endl;
        std::cout << "Fecha: "; 
        vecExamen[i].getFecha().mostrar();
        std::cout << "Legajo: " << vecExamen[i].getLegajo() << std::endl;
        std::cout << "Codigo de Materia: " << vecExamen[i].getCodMateria() << std::endl;
        std::cout << "Calificacion: " << vecExamen[i].getCalifiacion() << std::endl;
        std::string tipo = vecExamen[i].getTipoExamen() == 'p' || vecExamen[i].getTipoExamen() == 'P' ? "Parcial" : "Final";
        std::cout << "Tipo de examen: " << tipo;
        std::cout << std::endl;
        
    }
    delete[] vecExamen;
}

void ExamenManager::mostrarMejorNota()
{
    int legajo;
    std::cout << "Legajo: ";
    std::cin >> legajo;

    int codMateria;
    std::cout << "Codigo de materia: ";
    std::cin >> codMateria;

    int cantidadRegistros = _archivoExamen.getCantRegistros();
    if (cantidadRegistros == 0) {
        std::cout << "No hay examenes guardados." << std::endl;
        return;
    }

    Examen* vecExamen = new Examen[cantidadRegistros];
    _archivoExamen.leer(vecExamen, cantidadRegistros);

    float mejorNota = -1.0f;
    int idxMejor = -1;
    for (int i = 0; i < cantidadRegistros; ++i) {
        if (vecExamen[i].getLegajo() == legajo &&
            vecExamen[i].getCodMateria() == codMateria)
        {
            char tipo = vecExamen[i].getTipoExamen();
            if (tipo == 'P' || tipo == 'p') {
                float nota = vecExamen[i].getCalifiacion();
                if (nota > mejorNota) {
                    mejorNota = nota;
                    idxMejor = i;
                }
            }
        }
    }

    if (idxMejor == -1) {
        std::cout << "No se encontraron parciales para el legajo " << legajo
            << " en la materia " << codMateria << "." << std::endl;
    }
    else {
        std::cout << std::endl << "Mejor calificacion: " << mejorNota << std::endl;
        std::cout << "Fecha del examen: ";
        vecExamen[idxMejor].getFecha().mostrar();
    }

    delete[] vecExamen;

}

