#include "users.h"

int main()
{
    User mat[12][5];
    int sizes[12] = {};

    int option;
    do
    {
        option = menu();

        switch (option)
        {
        case 1:
            addUser(mat, sizes);
            break;

        case 2:
            searchByMonth(mat, sizes);
            break;

        case 3:
            dayFibonacci(mat, sizes);
            break;

        case 4:
            searchByGender(mat, sizes);
            break;

        case 0:
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (option != 0);
}