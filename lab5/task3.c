#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

    int rows = 5, columns = 5;
    int **arr = (int **) malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        *(arr + i) = (int *) malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++) {
            *(*(arr + i) + j) = i * 5 + j;
        }
    }
    for (int j = 0; j < columns; j++){
        int pos = 1;
        for (int i = 0; i < rows; i++){
            if (matrix[i][j] > 0){
                pos = 0
            }

        }

    }
    removeColumn(arr, rows, &columns, 3);
    printf("res:\n");
    for (int i = 0; i < rows; i++) {
        out_row(*(arr+i), columns);
        printf("\n");
    }


    return 0;
}