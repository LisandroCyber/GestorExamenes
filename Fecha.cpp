#include <iostream>
#include <sstream> /// para crear el toString
#include <string> /// para crear el toString
#include "fecha.h"

int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

void Fecha::setDia(int dia) {
    _dia = dia;
}

void Fecha::setMes(int mes) {
    _mes = mes;
}

void Fecha::setAnio(int anio) {
    _anio = anio;
}

bool Fecha::esBisiesto(int anio) {
    return (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0);
}

bool Fecha::esFechaValida() {
    if (_anio < 1 || _mes < 1 || _mes > 12) {
        return false;
    }

    int diasDelMes;

    if (_mes == 2) {
        diasDelMes = esBisiesto(_anio) ? 29 : 28;
    }
    else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) {
        diasDelMes = 30;
    }
    else {
        diasDelMes = 31;
    }

    return _dia >= 1 && _dia <= diasDelMes;
}

void Fecha::cargar() {
    do {
        std::cout << "Dia: ";
        std::cin >> _dia;

        std::cout << "Mes: ";
        std::cin >> _mes;

        std::cout << "Anio: ";
        std::cin >> _anio;

        if (!esFechaValida()) {
            std::cout << "\nFecha invalida. Ingresela nuevamente.\n\n";
        }

    } while (!esFechaValida());
}

void Fecha::mostrar() {
    std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}

Fecha::Fecha(int d, int m, int a) {
    _dia = d;
    _mes = m;
    _anio = a;
}

bool Fecha::operator==(const Fecha& aux) {
    if (_dia != aux._dia)return false;
    if (_mes != aux._mes)return false;
    if (_anio != aux._anio)return false;
    return true;
}

std::string Fecha::toString() {
    std::ostringstream oss;
    if (_dia < 10) oss << '0';
    oss << _dia << '/';
    if (_mes < 10) oss << '0';
    oss << _mes << '/';
    oss << _anio;
    return oss.str();
}
