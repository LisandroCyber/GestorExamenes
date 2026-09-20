#define _CRT_SECURE_NO_WARNINGS  /// alternatica para no usar fopen_s

#include "ExamenArchivo.h"
#include <cstdio>
ExamenArchivo::ExamenArchivo(std::string nombreArchivo) 
    : _nombreArchivo(nombreArchivo) {}

void ExamenArchivo::guardar(Examen examen)
{
    FILE* pArchivoExamen = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivoExamen == nullptr) {
        return;
    }

    fwrite(&examen, sizeof(Examen), 1, pArchivoExamen);

    fclose(pArchivoExamen);

}

void ExamenArchivo::leer(Examen examen[], int pos)
{
    FILE* pArchivoExamen = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivoExamen == NULL) {
        return ;
    }

    fread(examen, sizeof(Examen), pos, pArchivoExamen);

    fclose(pArchivoExamen);

}

int ExamenArchivo::getCantRegistros() {
    FILE* pArchivoExamen;

    pArchivoExamen = fopen(_nombreArchivo.c_str(), "rb");

    if (pArchivoExamen == NULL) {
        return 0;
    }

    fseek(pArchivoExamen, 0, SEEK_END);

    int cantidad = ftell(pArchivoExamen) / sizeof(Examen);

    fclose(pArchivoExamen);

    return cantidad;
}


