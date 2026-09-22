#define _CRT_SECURE_NO_WARNINGS  /// alternativa para no usar fopen_s

#include "ExamenManager.h"
#include "ExamenArchivo.h"
#include "Examen.h"
#include "Fecha.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

ExamenManager::ExamenManager(const std::string& nombreArchivo)
    : _nombreArchivo(nombreArchivo)
{
}

void ExamenManager::crearExamen()
{
    Fecha fecha;
    system("cls");
    std::cout << "Cargar fecha del examen: " << std::endl << std::endl;
    fecha.cargar();

    int legajo;
    do {
        std::cout << "Legajo: ";
        std::cin >> legajo;
        if (legajo < 0) {
            std::cout << "Numero de legajo Incorrecto (Debe ser mayor que 0)." << std::endl;
        }
    } while (legajo < 0);

    int codMateria;
    do {
        std::cout << "Codigo de materia: ";
        std::cin >> codMateria;
        if (codMateria < 0) {
            std::cout << "Codigo de materia Incorrecto (Debe ser mayor que 0)." << std::endl;
        }
    } while (codMateria < 0);

    float calificacion;
    do {
        std::cout << "Calificacion (0-10): ";
        std::cin >> calificacion;    
        if (calificacion < 0.f || calificacion > 10.f) {
            std::cout << "Calificacion Incorrecta (Debe ser mayor que 0 y como maximo 10)." << std::endl;            
        }
    } while (calificacion < 0 || calificacion > 10);

    char tipo;
    do {
        std::cout << "Tipo de examen (P o F): ";
        std::cin >> tipo;
        if (tipo != 'P' && tipo != 'p' && tipo != 'F' && tipo != 'f') {
            std::cout << "Tipo de examen Incorrecto ('P' Parcial / 'F' Final): " << std::endl;
        }
    } while (tipo != 'P' && tipo != 'p' && tipo != 'F' && tipo != 'f');

    Examen examen(fecha, legajo, codMateria, calificacion, tipo); // valores validados

    _archivoExamen.guardar(examen);

    std::cout << std::endl << "Examen guardado correctamente." << std::endl;
    std::cout << "Presione una tecla para volver al Menu Principal..." << std::endl;
    system("pause>nul");
    system("cls");
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
    system("cls");
    std::cout << std::endl << std::left
        << std::setw(10) << "LEGAJO"
        << std::setw(15) << "COD. MATERIA"
        << std::setw(15) << "FECHA"
        << std::setw(15) << "TIPO EXAMEN"
        << std::right << std::setw(12) << "CALIFICACION"
        << std::endl;

    std::cout << "====================================================================" << std::endl;

    for (int i = 0; i < cantidadRegistros; i++) {
        vecExamen[i].mostrarEnLista();
    }
    std::cout << "====================================================================" << std::endl;

    std::cout << std::endl << "Presione una tecla para volver al Menu Principal..." << std::endl;
    system("pause>nul");
    system("cls");
    delete[] vecExamen;
}

void ExamenManager::mostrarMejorNota()
{
    int legajo;
    do {
        system("cls");
        std::cout << "BUSCAR MEJOR NOTA POR LEGAJO Y CODIGO DE MATERIA" << std::endl;
        std::cout << std::endl << "Legajo: ";
        std::cin >> legajo;
        if (legajo < 0) {
            std::cout << "Numero de legajo Incorrecto (Debe ser mayor que 0)." << std::endl;
            std::cout << "Legajo: ";
        }
    } while (legajo < 0);

    int codMateria;
    do {
        std::cout << "Codigo de materia: ";
        std::cin >> codMateria;
        if (codMateria < 0) {
            std::cout << "Codigo de materia Incorrecto (Debe ser mayor que 0)." << std::endl;
            std::cout << "Codigo de materia: ";
        }
    } while (codMateria < 0);

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
        std::cout << std::endl << "No se encontraron parciales para el legajo " << legajo
            << " en la materia " << codMateria << "." << std::endl;
    }
    else {
        std::cout << std::endl << "Mejor calificacion: " << mejorNota << std::endl;
        std::cout << "Fecha del examen: ";
        vecExamen[idxMejor].getFecha().mostrar();
    }

    delete[] vecExamen;
    std::cout << std::endl << "Presione una tecla para volver al Menu Principal..." << std::endl;
    system("pause>nul");
    system("cls");
}



