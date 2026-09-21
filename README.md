# Gestor de Exámenes

Aplicación de consola desarrollada en **C++** para registrar exámenes de alumnos, almacenarlos en un archivo binario y consultar la mejor nota obtenida en un examen parcial.

El proyecto fue realizado como práctica de **Programación Orientada a Objetos y manejo de archivos**.

## Funcionalidades

El menú principal permite:

1. **Cargar un examen**
   - Solicita la fecha.
   - Solicita el legajo del alumno.
   - Solicita el código de materia.
   - Solicita la calificación.
   - Solicita el tipo de examen: parcial o final.
   - Guarda el registro en el archivo binario `Examenes.dat`.

2. **Listar exámenes**
   - Lee todos los registros almacenados.
   - Muestra la fecha, el legajo, el código de materia, la calificación y el tipo de examen.

3. **Buscar la mejor nota**
   - Solicita un legajo y un código de materia.
   - Busca únicamente exámenes de tipo parcial.
   - Muestra la calificación más alta y la fecha en la que fue obtenida.
   - Informa al usuario cuando no existen parciales que coincidan con la búsqueda.

## Menú principal

```text
------ MENU ------
1 - Cargar Examen
2 - Listar Examenes
3 - Buscar mejor nota
0 - Salir
```

## Datos de un examen

Cada examen contiene los siguientes datos:

| Campo | Tipo | Descripción |
| --- | --- | --- |
| Fecha | `Fecha` | Día, mes y año del examen |
| Legajo | `int` | Número de legajo del alumno |
| Código de materia | `int` | Identificador de la materia |
| Calificación | `float` | Nota del examen, prevista entre 0 y 10 |
| Tipo de examen | `char` | `P` para parcial o `F` para final |

## Estructura del proyecto

| Archivo | Responsabilidad |
| --- | --- |
| `main.cpp` | Inicia la aplicación y ejecuta el menú principal |
| `Fecha.h` / `Fecha.cpp` | Representan y administran el día, mes y año |
| `Examen.h` / `Examen.cpp` | Definen la entidad examen y sus propiedades |
| `ExamenArchivo.h` / `ExamenArchivo.cpp` | Guardan y leen registros del archivo binario |
| `ExamenManager.h` / `ExamenManager.cpp` | Contienen la lógica para crear, listar y buscar exámenes |
| `Menu.h` / `Menu.cpp` | Implementan el menú base de la aplicación |
| `MenuGestorExamenes.h` / `MenuGestorExamenes.cpp` | Conectan las opciones del menú con el gestor de exámenes |
| `Examenes.dat` | Archivo binario que contiene los registros guardados |

## Clases principales

### `Fecha`

Almacena los tres números que forman una fecha:

- Día.
- Mes.
- Año.

También permite cargarla, mostrarla y comparar dos fechas.

### `Examen`

Representa un examen mediante una fecha, un legajo, un código de materia, una calificación y un tipo de examen. Incluye constructores, getters y setters para administrar sus datos.

### `ExamenArchivo`

Se encarga de la persistencia de los registros:

- `guardar()`: agrega un examen al final de `Examenes.dat`.
- `leer()`: lee los exámenes almacenados.
- `getCantRegistros()`: calcula la cantidad de registros existentes.

### `ExamenManager`

Administra las operaciones principales del sistema:

- `crearExamen()`.
- `listarTodos()`.
- `mostrarMejorNota()`.

### `MenuGestorExamenes`

Muestra el menú principal y ejecuta la opción elegida por el usuario.

## Persistencia de datos

Los exámenes se almacenan en el archivo binario `Examenes.dat`. Cada nueva carga se agrega al final del archivo, por lo que los datos se conservan entre ejecuciones mientras el archivo permanezca en el directorio de trabajo del programa.

> **Importante:** el nombre utilizado actualmente por el proyecto comienza con mayúscula: `Examenes.dat`.

## Requisitos

- Compilador compatible con C++.
- Visual Studio con soporte para desarrollo de escritorio en C++, o un compilador equivalente.
- Consola o terminal para interactuar con el menú.

## Compilación y ejecución

### Visual Studio

1. Abrir `Project1.slnx`.
2. Compilar la solución.
3. Ejecutar el proyecto.
4. Elegir una opción del menú ingresando su número.

## Estado actual del proyecto

Las funciones principales del enunciado se encuentran implementadas: carga de exámenes, almacenamiento en archivo, listado de registros y búsqueda de la mejor nota parcial.

### Pendiente

El proyecto todavía se encuentra en desarrollo y faltan los siguientes ajustes:

- Agregar validaciones para la fecha ingresada.
- Validar que el legajo y el código de materia sean valores correctos.
- Validar que la calificación esté entre **0 y 10**.
- Validar que el tipo de examen sea solamente **P** o **F**.
- Controlar entradas no numéricas y errores de lectura o escritura del archivo.
- Impedir, de manera opcional, que se repita la combinación de legajo, código de materia y fecha.
- Dar al listado de exámenes el formato tabular solicitado en el enunciado, con las columnas alineadas: **LEGAJO, IDMATERIA, FECHA, TIPO y CALIFICACIÓN**.
- Implementar opcionalmente un método `ToString()`.
- Adaptar, si se requiere cumplir literalmente la consigna, el método `leer()` para recibir un índice y devolver un único examen.

Por el momento, la opción **Listar exámenes** muestra correctamente los datos, pero lo hace registro por registro y todavía no posee el formato final solicitado.

## Enunciado resumido

La actividad propone desarrollar una aplicación de consola que utilice clases y archivos para:

- Modelar un examen.
- Aplicar encapsulamiento mediante getters y setters.
- Guardar y recuperar información desde un archivo binario.
- Separar la lógica de almacenamiento, administración y presentación.
- Ofrecer un menú que permita cargar, listar y buscar exámenes.
