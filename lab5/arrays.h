#include <stdio.h>
#include <stdlib.h>


void out_row(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void fill_row(int **arr, int len) {
    *arr = (int *) malloc(len * sizeof(int *));
    for (int i = 0; i < len; i++) {
        (*arr)[i] = i;
    }
}

void power_row(int *arr, int len) {
    for (int i = len - 1; i >= 0; i--) {
        arr[i * 2 + 1] = arr[i] * arr[i];
        arr[i * 2] = arr[i];
    }
}

void removeColumn(int **matrix, int rows, int *cols, int index) {
    (*cols)--;

    for (int i = 0; i < rows; i++) {
        for (int j = index; j <= *cols; j++) {
            matrix[i][index] = matrix[i][index + 1];
        }
        matrix[i] = realloc(matrix[i], sizeof(double) * *cols );
    }


}
//void print(int **matrix, int rows, int cols) {
//    // printf("%d\n", matrix[3][3]);//*(*(matrix + 3)+ 4)) ;
//
//    for (int j = 0; j < cols; j++) {
//        // printf("j: %d ", j);
//
//
//            matrix[i][j] = matrix[i][j + 1];
//
//        }
//
//        printf("\n");
//    }
//}
//    for (int i = 0; i < *rows; i++) {
//        out_row(*matrix, *cols);
//        printf("\n");
//        while (index < *cols) {
//            matrix[i][index] = matrix[i][index + 1];
//            index++;
//        }
//        matrix[i] = realloc(matrix[i], sizeof(double) * *cols);
//    }
