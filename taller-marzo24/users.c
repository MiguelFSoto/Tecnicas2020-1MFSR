#include "users.h"

int menu()
{
    int option;
    printf("Seleccione la accion:\n");
    printf("1: Ingresar usuario\n");
    printf("2: Mostrar por mes\n");
    printf("3: Numero de Fibonacci\n");
    printf("4: Mostrar por genero\n");
    printf("0: Salir\n");
    scanf("%d", &option);

    return option;
}

void addUser(User mat[][5], int sizes[])
{
    int day, month, year;
    char name[20];

    printf("Nombre: ");
    scanf("%s", &name);

    printf("Anio: ");
    scanf("%d", &year);

    printf("Mes: ");
    scanf("%d", &month);

    printf("Dia: ");
    scanf("%d", &day);

    printf("Genero:\n1)Hombre\n2)Mujer\n");
    int genderChoice;
    scanf("%d", &genderChoice);

    if (sizes[month - 1] < 5)
    {
        Gender g = genderChoice == 1 ? Male : Female;
        User u;
        strcpy(u.name, name);
        u.day = day;
        u.year = year;
        u.gender = g;
        mat[month - 1][sizes[month - 1]] = u;
        sizes[month - 1]++;
    }
    else
        printf("No hay mas espacio para el mes %d\n", month);
}

void searchByMonth(User mat[][5], int sizes[])
{
    int month;
    printf("Mes: ");
    scanf("%d", &month);

    int i;
    for (i = 0; i < sizes[month - 1]; i++)
    {
        User u = mat[month - 1][i];
        printf("Nombre: %s\nFecha de nacimiento: %d/%d/%d\nGenero:", u.name, u.day, month, u.year);
        if (u.gender == Male)
            printf(" Hombre\n------------\n");
        else
            printf(" Mujer\n------------\n");
    }
}

int fibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void dayFibonacci(User mat[][5], int sizes[])
{
    char name[20];

    printf("Nombre: ");
    scanf("%s", &name);

    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            User u = mat[i][j];

            if (!strcmp(u.name, name))
                printf("Numero: %d\n", fibonacci(u.day));
        }
    }
}

void searchByGender(User mat[][5], int sizes[])
{
    printf("Genero:\n1)Hombre\n2)Mujer\n");
    int genderChoice;
    scanf("%d", &genderChoice);
    Gender g = genderChoice == 1 ? Male : Female;

    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            User u = mat[i][j];

            if (u.gender == g)
                printf("Nombre: %s\nFecha de nacimiento: %d/%d/%d\n-----------\n", u.name, u.day, i + 1, u.year);
        }
    }
}