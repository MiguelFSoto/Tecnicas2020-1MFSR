#include <stdio.h>
#include <string.h>

enum Gender
{
    c,
    Female
};

typedef enum Gender Gender;

struct User
{
    char name[20];
    int day;
    int year;
    Gender gender;
};

typedef struct User User;

int menu();

void addUser(User mat[][5], int sizes[]);

void searchByMonth(User mat[][5], int sizes[]);

int fibonacci(int n);

void dayFibonacci(User mat[][5], int sizes[]);

void searchByGender(User mat[][5], int sizes[]);