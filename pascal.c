#include "main.h"

int **pascal_triangle(int n)
{
    int numrow;
    int **triangle = NULL;
    int i, j;

    if (n <= 0)
        return (triangle);
    
    numrow = n;
    // Allocate Memory for the List of Lists
    triangle = malloc(numrow * sizeof(int *));
    if (triangle == NULL)
    {
        fprintf(stderr, "Error: Failed to Allocated Memory\n");
        return (triangle);
    }

    // Allocate memory for each list based on Num of row
    for (i = 0; i < numrow; i++)
    {
        triangle[i] = malloc((i + 1) * sizeof(int));

            if (triangle[i] == NULL)
            {
                fprintf(stderr, "Error: Failed to Allocated Memory\n");

                for (j = 0; j < i ; j++)
                {
                    free(triangle[j]);
                }
                free(triangle);

                return (NULL);
            }

    }

    // Set the First Values
    for (i = 0; i < numrow; i++)
    {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
    }

    // Fill the Inner Elements  

    for (i = 2; i < numrow; i++)
    {
        for (j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return (triangle);
}