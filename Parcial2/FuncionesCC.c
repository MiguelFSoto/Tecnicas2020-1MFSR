#include "FuncionesCC.h"


//Esta funcion imprime los datos de un local en una posicion
void mostrarLocal(local_t **centroComercial, int piso, int local, int pisos, int localesPiso)
{
    //Revisa que la posicion no se pase de los tamaños
    if (piso < pisos && local < localesPiso)
    {
        //Revisa si el local esta ocupado
        if (centroComercial[piso][local].idLocal != 0)
        {
            printf("Nombre local : %s\n", centroComercial[piso][local].nombreLocal);
            printf("Id local : %d\n", centroComercial[piso][local].idLocal);
            printf("Estado: ");
            if (centroComercial[piso][local].estado == abierto)
                printf("Abierto\n");
            else
                printf("Cerrado\n");
            printf("Total de ventas: %f\n", centroComercial[piso][local].ventas);
        }
        else
            printf("Local no ocupado\n");
    }
}

//Esta funcion asigna la memoria para la matriz que representa el centro comercial
local_t** crearCC(int pisos, int localesPiso)
{
    local_t** centroComercial = malloc(sizeof(local_t*) * pisos);

    int i, j;
    for(i = 0; i < pisos; i++)
    {
        centroComercial[i] = malloc(sizeof(local_t) * localesPiso);
        for (j = 0; j < localesPiso; j++)
            //Inicia todos los id en 0 para representar que los locales estan vacios
            centroComercial[i][j].idLocal = 0;
    }

    return centroComercial;
}

//Esta funcion crea un local en una posicion que no estuviera ocupada
void crearLocal(local_t **centroComercial, int pisos, int localesPiso)
{
    //Pide la ubicacion a cambiar hasta obtener una valida
    int piso, local;
    while (1)
    {
        printf("Piso: ");
        scanf("%d", &piso);
        printf("Local: ");
        scanf("%d", &local);

        //Se le resta a los valores para poderlos usar como indices de la matriz
        piso--;
        local--;
        if (piso >= pisos || local >= localesPiso)
            printf("Fuera de rango\n");
        if (centroComercial[piso][local].idLocal != 0)
            printf("Local ya ocupado\n");
        else
            break;
    }

    //Pide el nombre al usuario e inicializa los valores del local
    printf("Nombre del local: ");
    scanf("%35s", centroComercial[piso][local].nombreLocal);
    centroComercial[piso][local].idLocal = (piso + 1) * 100 + (local + 1);
    centroComercial[piso][local].pisoLocal = piso;
    centroComercial[piso][local].numLocalxPiso = local;
    centroComercial[piso][local].estado = cerrado;
    centroComercial[piso][local].ventas = 0;
}

//Esta funcion muestra recursivamente los locales de un piso
void mostrarPiso(local_t **centroComercial, int piso, int pisos, int localesPiso, int local)
{
    //Al llamar la funcion por primera vez, se le asigna a piso el valor de -1
    //Esto representa que aun no se le ha pedido este valor al usuario
    if (piso == -1)
    {
        printf("Piso: ");
        scanf("%d", &piso);
        //Se le resta para usarlo como indice
        piso--;
    }

    //Se revisa que el piso que dio el usuario este en el rango
    if (piso < pisos)
    {
        //Condicion de salida
        if (local != localesPiso)
        {
            mostrarLocal(centroComercial, piso, local, pisos, localesPiso);
            printf("\n");
            //Se le suma 1 a local para mostrar la siguiente posicion en la proxima iteracion
            mostrarPiso(centroComercial, piso, pisos, localesPiso, local + 1);
        }
    }
    else
    {
        //Si no lo esta, se vuelve a pedir el dato
        printf("Piso fuera de rango\n");
        mostrarPiso(centroComercial, -1, pisos, localesPiso, local);
    }
}

//Esta funcion devuelve la direccion de un local que se busca por nombre
local_t* obtenerLocal(local_t **centroComercial, int pisos, int localesPiso)
{
    char nombre[35];
    printf("Nombre del local: ");
    scanf("%34s", nombre);

    //Se recorre la matriz usando dos ciclos
    int i, j;
    for (i = 0; i < pisos; i++)
    {
        for (j = 0; j < localesPiso; j++)
        {
            //Si los nombres son iguales, devuelve la direccion
            if (!strcmp(centroComercial[i][j].nombreLocal, nombre))
                return &centroComercial[i][j];
        }
    }

    //Si no se encontro el nombre dado, la funcion devuelve NULL
    return NULL;
}

//Esta funcion imprime los datos de un local que se busca por nombre
void buscarNombre(local_t **centroComercial, int pisos, int localesPiso)
{
    //Se obtiene la direccion del local a buscar
    local_t* local = obtenerLocal(centroComercial, pisos, localesPiso);

    //Se revisa que si se haya encontrado el local deseado
    if (local != NULL)
    {
        //Se revisa que el local este ocupado
        if (local->idLocal != 0)
        {
            printf("Id Local: %d\n", local->idLocal);
            printf("Piso: %d\n", local->pisoLocal + 1);
            printf("Local: %d\n", local->numLocalxPiso + 1);
            if (local->estado == abierto)
                printf("Abierto\n");
            else
                printf("Cerrado\n");
            printf("Total de ventas: %f\n", local->ventas);
        }
        else
            printf("Local no encontrado\n");
    }
    else
        printf("Local no encontrado\n");
}   

//Esta funcion edita el nombre de un local usando su direccion
void editarNombre(local_t *local)
{
    char nombre[35];
    printf("Nombre Nuevo: ");
    scanf("%34s", nombre);
    strcpy(local->nombreLocal, nombre);
}

//Esta funcion cambia el nombre de un local dado su nombre actual
void cambiarNombreLocal(local_t **centroComercial, int pisos, int localesPiso)
{
    //Se obtiene el local a editar
    local_t *local = obtenerLocal(centroComercial, pisos, localesPiso);

    //Se revisa que el local exista y este ocupado
    if (local != NULL)
    {
        if (local->idLocal != 0)
            //Se llama a la funcion anterior para hacer el cambio
            editarNombre(local);
        else
            printf("Local no encontrado\n");
    }
    else
        printf("Local no encontrado\n");
}

//Esta funcion alterna el estado de un local que se busca por nombre
void cambiarEstado(local_t **centroComercial, int pisos, int localesPiso)
{
    //Se obtiene el local a editar
    local_t *local = obtenerLocal(centroComercial, pisos, localesPiso);

    //Se revisa que el local exista y este ocupado
    if (local != NULL)
    {
        if (local->idLocal != 0)
        {
            //Se cambia el estado del local al opuesto del actual
            if (local->estado == abierto)
                local->estado = cerrado;
            else
                local->estado = abierto;
        }
        else
            printf("Local no encontrado\n");
    }
    else
        printf("Local no encontrado\n");
}

//Esta funcion registra una compra para un local que se busca por nombre
void realizarCompra(local_t **centroComercial, int pisos, int localesPiso)
{
    //Se obtiene el local a editar
    local_t *local = obtenerLocal(centroComercial, pisos, localesPiso);

    //Se revisa que el local exista y este ocupado
    if (local != NULL)
    {
        if (local->idLocal != 0)
        {
            //Para hacer la compra, se necesita que el local este abierto
            if (local->estado == abierto)
            {
                //Se pide el valor de la compra y se agrega a las ventas del local
                float venta;
                printf("Valor de la compra: ");
                scanf("%f", &venta);

                local->ventas += venta;
            }
            else
                printf("El local esta cerrado\n");
        }
        else
            printf("Local no encontrado\n");
    }
    else
        printf("Local no encontrado\n");
}

//Esta funcion elimina un local que esta ocupado
void eliminarLocal(local_t **centroComercial, int pisos, int localesPiso)
{
    //Se pide la posicion a eliminar hasta que esta sea valida
    int piso, local;
    while (1)
    {
        printf("Piso: ");
        scanf("%d", &piso);
        printf("Local: ");
        scanf("%d", &local);

        //Se le resta a los valores para poderlos usar como indices de la matriz
        piso--;
        local--;
        if (piso >= pisos || local >= localesPiso)
            printf("Fuera de rango\n");
        else if (centroComercial[piso][local].idLocal == 0)
            printf("Local no ocupado\n");
        else
            break;
    }

    //Se actualiza el id de la ubicacion que dio usuario a 0
    centroComercial[piso][local].idLocal = 0;
}

//Esta funcion añade un piso nuevo al centro comercial para aumentar su capacidad
void construirPiso(local_t **centroComercial, int* pisos, int localesPiso)
{
    //Se aumenta el tamaño de la memoria asignada a la matriz
    centroComercial = realloc(centroComercial, sizeof(local_t*) * (*pisos + 1));
    //Se hace la asignacion de la memoria para el nuevo piso
    centroComercial[*pisos] = malloc(sizeof(local_t) * localesPiso);

    //Se inicializazn los id del nuevo piso en 0 para representar que no estan ocupados
    int i;
    for (i = 0; i < localesPiso; i++)
        centroComercial[*pisos][i].idLocal = 0;

    //Se actualiza la variable del tamaño
    *pisos += 1;
}