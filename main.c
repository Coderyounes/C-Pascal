#include "main.h"



int main(int argc, char *argv[])
{
    int num;
    int i, j;
    char *endptr;
    int **pascal;

    if (argc <= 1)
    {
        fprintf(stderr, "[%d] Argument, Make sure to supply one Integer", argc);
        return (-1);
    }

    num = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0')
    {
        fprintf(stderr, "Error: Invalid Integer");
        return (-1);
    }

    pascal = pascal_triangle(num);

    for (i = 0; i < num; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    return (0);
}