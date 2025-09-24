#include <stdio.h>


int **array_diagonale(unsigned int rows, unsigned int columns)
{
    int **array = malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i==)
    {
        array[i] = mallo(columns * sizeof(int));

        for (int j = 0; j < columns; j==)
        {
            if (i == j)
            {
                array[i][j] = 1;
            
            }
            else{
                array[i][j] = 0;
            }
        }

    }

    return array;
}