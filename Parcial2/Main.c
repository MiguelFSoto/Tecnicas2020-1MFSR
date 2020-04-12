#include "FuncionesCC.h"
#include <stdio.h>

//Funcion para imprimir el menu que devuelve la opcion que selecciona el usuario
int menu()
{
    int opcion;

    printf("Centro Comercial\n--------------------------\n");
    printf("1: Crear Local\n");
    printf("2: Mostrar Piso\n");
    printf("3: Buscar Local\n");
    printf("4: Cambiar Nombre\n");
    printf("5: Abrir/Cerrar Local\n");
    printf("6: Realizar Compra\n");
    printf("7: Eliminar Local\n");
    printf("8: Construir Piso\n");
    printf("9: Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

int main()
{
    //Dimensiones iniciales de la matriz
    int pisos, localesPiso;
    printf("Numero de pisos: ");
    scanf("%d", &pisos);
    printf("Numero de locales por piso: ");
    scanf("%d", &localesPiso);

    //Creacion de la matriz
    local_t** centroComercial = crearCC(pisos, localesPiso);

    //Ciclo principal donde el usuario selecciona la opcion
    int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
            case 1:
                crearLocal(centroComercial, pisos, localesPiso);
                break;

            case 2:
                mostrarPiso(centroComercial, -1, pisos, localesPiso, 0);
                break;

            case 3:
                buscarNombre(centroComercial, pisos, localesPiso);
                break;

            case 4:
                cambiarNombreLocal(centroComercial, pisos, localesPiso);
                break;

            case 5:
                cambiarEstado(centroComercial, pisos, localesPiso);
                break;

            case 6:
                realizarCompra(centroComercial, pisos, localesPiso);
                break;

            case 7:
                eliminarLocal(centroComercial, pisos, localesPiso);
                break;

            case 8:
                construirPiso(centroComercial, &pisos, localesPiso);
                break;

            case 9:
                break;

            default:
                printf("Opcion invalida\n");
                break;
        }
     } while (opcion != 9);

    return 0;
}