#include <stdio.h>

#include "TSMatrix.h"

int main()
{
    TSMatrix A = {
        6, 7, 8,
        {
            {0, 0, 0},
            {1, 2, 12},
            {1, 3, 9},
            {3, 1, -3},
            {3, 6, 14},
            {4, 3, 24},
            {5, 2, 18},
            {6, 1, 15},
            {6, 4, -7}
        }
    },
    B;

    PrintfTSMatrix(&A, "The original matrix is:");

    TransposeTSMatrix(&A, &B);
    PrintfTSMatrix(&B, "Transposed:");

    FastTransposeTSMatrix(&A, &B);
    PrintfTSMatrix(&B, "Fast transposed:");

    return 0;
}