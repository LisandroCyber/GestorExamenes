# Gestor de Exámenes

Aplicación de consola en **C++** para registrar exámenes de alumnos en un archivo binario, listarlos y consultar la mejor calificación obtenida en un parcial. Es una práctica de programación orientada a objetos y manejo de archivos.

## Funciones disponibles

Al iniciar, el menú ofrece estas opciones:

| Opción | Acción |
| --- | --- |
| `1` | Cargar un examen y agregarlo a `Examenes.dat`. |
| `2` | Listar los exámenes guardados en columnas: legajo, código de materia, fecha, tipo y calificación. |
| `3` | Buscar la mejor nota **parcial** de un alumno en una materia, indicando legajo y código. También muestra la fecha correspondiente. |
| `0` | Salir. |

Si no hay registros, el programa lo informa. Si la búsqueda no encuentra parciales para el legajo y la materia indicados, también muestra un aviso. Los exámenes finales no participan en la búsqueda de mejor nota.

## Datos y validaciones

Cada registro de `Examen` contiene:

| Campo | Tipo en C++ | Entrada aceptada |
| --- | --- | --- |
| Fecha | `Fecha` (tres `int`) | Día, mes y año válidos; se consideran los años bisiestos. |
| Legajo | `int` | Valor no negativo. |
| Código de materia | `int` | Valor no negativo. |
| Calificación | `float` | Entre 0 y 10, inclusive. |
| Tipo de examen | `char` | `P`/`p` para parcial o `F`/`f` para final. |

Ante una fecha o un valor fuera de esos rangos, se vuelve a solicitar la entrada. En el listado, la fecha se presenta como `dd/mm/aaaa` mediante `Fecha::toString()`, y la calificación se muestra con dos decimales.

## Organización del código

| Archivos | Responsabilidad |
| --- | --- |
| `main.cpp` | Crea y ejecuta el menú. |
| `Fecha.h` y `Fecha.cpp` | Representan la fecha, comprueban días por mes y años bisiestos, y generan su texto. |
| `Examen.h` y `Examen.cpp` | Representan un examen y muestran cada registro como una fila del listado. |
| `ExamenArchivo.h` y `ExamenArchivo.cpp` | Agregan registros al archivo binario, leen los registros y cuentan cuántos hay. |
| `ExamenManager.h` y `ExamenManager.cpp` | Gestionan la carga, el listado y la búsqueda de la mejor nota. |
| `Menu.h` y `Menu.cpp` | Definen el menú reutilizable. |
| `MenuGestorExamenes.h` y `MenuGestorExamenes.cpp` | Asocian cada opción con su operación. |

`Examenes.dat` se crea en el directorio de trabajo del programa cuando se guarda un examen. Los registros se agregan al final del archivo; al volver a ejecutar la aplicación desde ese mismo directorio, se pueden consultar los datos guardados.

## Ejecutar

El código utiliza `system("cls")` y `system("pause>nul")`, por lo que la interfaz está pensada para la consola de **Windows**. Para ejecutarlo desde Visual Studio, creá un proyecto de **Aplicación de consola de C++**, agregá los archivos `.h` y `.cpp` del repositorio, compilá y ejecutá `main.cpp`.

## Estado y mejoras pendientes

La carga, el guardado, el listado tabular y la búsqueda de la mejor nota parcial están implementados. Todavía quedan estos puntos por mejorar:

- Manejar entradas no numéricas: actualmente pueden dejar `std::cin` en estado de error.
- Verificar y comunicar los fallos de apertura, lectura o escritura del archivo. La carga muestra un mensaje de éxito aunque `guardar()` no haya podido abrirlo.
- Ajustar la validación de legajo y código de materia si deben ser **mayores que cero**: la condición actual permite el cero.
- Definir si deben admitirse exámenes repetidos para la misma combinación de legajo, materia y fecha.
- Revisar los setters de `Examen` si se necesitan desde fuera de la clase: actualmente son privados.
