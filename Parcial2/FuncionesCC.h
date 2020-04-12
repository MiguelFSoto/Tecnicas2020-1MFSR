#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Enum para representar si un local esta abierto o cerrado
typedef enum Estado
{
    abierto,
    cerrado
}   estado_t;

typedef struct Local
{
    char nombreLocal[35];
    // Los id depeneden del piso y ubicacion dentro de este de cada local
    // Un id igual a 0 representa que el local esta vacio
    int idLocal;
    int pisoLocal;
    int numLocalxPiso; 
    estado_t estado;
    //Total de ventas para cada local
    float ventas;
} local_t;

void mostrarLocal(local_t **centroComercial, int numPiso,
                  int numLocalxPiso, int numPisos, int numLocalesxPiso);

local_t** crearCC(int pisos, int localesPiso);

void crearLocal(local_t **centroComercial, int pisos, int localesPiso);

void mostrarPiso(local_t **centroComercial, int piso, int pisos, int localesPiso, int local);

local_t* obtenerLocal(local_t **centroComercial, int pisos, int localesPiso);

void buscarNombre(local_t **centroComercial, int pisos, int localesPiso);

void editarNombre(local_t *local);

void cambiarNombreLocal(local_t **centroComercial, int pisos, int localesPiso);

void cambiarEstado(local_t **centroComercial, int pisos, int localesPiso);

void realizarCompra(local_t **centroComercial, int pisos, int localesPiso);

void eliminarLocal(local_t **centroComercial, int pisos, int localesPiso);

void construirPiso(local_t **centroComercial, int* pisos, int localesPiso);

#endif /* FUNCIONESCC_H_ */