#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrixA[4][4] =
    {
        {22, 45, 32, 35},
        {76, 98, 34, 12},
        {18, 23, 10, 34},
        {87, 67, 34, 25}
    };

    int matrixB[4][4] =
    {
        {32, 15, 54, 75},
        {46, 18, 60, 82},
        {53, 13, 36, 74},
        {66, 17, 42, 95}
    };

    int matrixC[4][4] = {0};
    int d = 4;

    printf("|-------| MATRIX A |-------|\n");
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (matrixA[i][j] >= 10 && matrixA[i][j] < 100)
                printf(" %d    ", matrixA[i][j]);
            else if (matrixA[i][j] > 100)
                printf(" %d   ", matrixA[i][j]);
            else
                printf(" %d  ", matrixA[i][j]);

        }
        printf("\n");
    }
    printf("\n\n");

    printf("|-------| MATRIX B |-------|\n");
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (matrixB[i][j] >= 10 && matrixB[i][j] < 100)
                printf(" %d    ", matrixB[i][j]);
            else if (matrixB[i][j] > 100)
                printf(" %d   ", matrixB[i][j]);
            else
                printf(" %d  ", matrixB[i][j]);

        }
        printf("\n");
    }
    printf("\n\n");

    printf("|-------| MATRIX C |-------|\n");
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];

            if (matrixC[i][j] >= 10 && matrixC[i][j] < 100)
                printf(" %d    ", matrixC[i][j]);
            else if (matrixC[i][j] > 100)
                printf(" %d   ", matrixC[i][j]);
            else
                printf(" %d  ", matrixC[i][j]);

        }
        printf("\n");
    }
    printf("\n\n");


    return 0;
}
