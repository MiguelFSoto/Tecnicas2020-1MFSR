#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(0);
    printf("\nEnd time is %s\n", ctime(&t));

    return 0;
}