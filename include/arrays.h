#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"

#ifndef ARRAYS_H
#define ARRAYS_H


typedef struct {
    int character;
    int *arr;
} td_array;


typedef enum {
    false, true
} bool;


void print_row(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void fill_array(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        input(&arr[i], INT_MIN, INT_MAX, "Input elem:");
    }
}

void fill_random_array(int *arr, int len, int max) {

    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (2 * max) - max;
    }
}

void fill_matrix(int **arr, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(columns * sizeof(int));
        fill_array(arr[i], columns);
    }
}


void fill_2d_array(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {

        int inp = 0;
        arr[i].character = 0;
        arr[i].arr = (int *) malloc(0);

        while (inp != -1) {

            input(&inp, -1, INT_MAX, "Input elem:");
            if (inp == -1) { break; }

            arr[i].character++;
            arr[i].arr = (int *) realloc(arr[i].arr, arr[i].character * sizeof(int *));
            arr[i].arr[arr[i].character - 1] = inp;
        }
    }
}

void print_2d_array(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {
        print_row(arr[i].arr, arr[i].character);
        printf("\n");
    }
}


void print_matrix(int **matrix, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        print_row(matrix[i], columns);
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

void remove_columns_after_index(td_array *arr, int rows, int start_index) {

    for (int i = 0; i < rows; i++) {

        if (arr[i].character < start_index) { continue; }
        arr[i].character = start_index;
    }
}

#endif