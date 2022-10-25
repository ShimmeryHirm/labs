#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;


void input(int *var, int min, int max, char *str) {

    printf("%s", str);
    while (!scanf("%d", var) || *var > max || *var < min || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}


void out_row(int *arr, int len, bool t2) {

    for (int i = 0; i < len; i++) {
        if (t2 && arr[i] == -1) {
            break;
        }
        printf("%d ", arr[i]);
    }
}


void fill_array(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        input(&arr[i], INT_MIN, INT_MAX, "Input elem:");
    }
}


void fill_matrix(int **arr, int rows, int columns, int lim) {

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++) {
            input(&arr[i][j], lim, INT_MAX, "Input elem:");
        }
    }
}


void fill_2d_array(int **arr, int rows, int *max_column) {

    for (int i = 0; i < rows; i++) {

        int columns = 0, inp = 0;
        arr[i] = (int *) malloc(columns * sizeof(int *));

        while (inp != -1) {
            input(&inp, -1, INT_MAX, "Input elem:");
            columns++;
            arr[i] = (int *) realloc(*(arr + i), columns * sizeof(int *));
            arr[i][columns - 1] = inp;
        }

        if (columns > *max_column) {
            *max_column = columns;
        }
    }
}


void print_matrix(int **matrix, int rows, int columns, bool t2) {

    for (int i = 0; i < rows; i++) {
        out_row(*(matrix + i), columns, t2);
        printf("\n");
    }
}


void power_array(int *arr, int len) {

    for (int i = len - 1; i >= 0; i--) {
        arr[i * 2 + 1] = arr[i] * arr[i];
        arr[i * 2] = arr[i];
    }
}


void remove_column(int **arr, int rows, int *columns, int index) {

    (*columns)--;

    for (int i = 0; i < rows; i++) {

        for (int j = index; j <= *columns; j++) {
            arr[i][j] = arr[i][j + 1];
        }
        arr[i] = realloc(arr[i], sizeof(double) * *columns);
    }
}


void remove_neg_columns(int **arr, int rows, int *columns) {

    for (int j = *columns - 1; j >= 0; j--) {

        bool negative = true;
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] >= 0) { negative = false; }
        }
        if (negative) { remove_column(arr, rows, columns, j); }

    }
}
