

#ifndef ARRAYS_H
#define ARRAYS_H


typedef struct {
    int character;
    int *arr;
} td_array;


typedef enum {
    false, true
} bool;


void print_row(int *arr, int len);

void fill_array(int *arr, int len);

void fill_random_array(int *arr, int len, int max);

void fill_matrix(int **arr, int rows, int columns);


void fill_2d_array(td_array *arr, int rows);

void print_2d_array(td_array *arr, int rows);


void print_matrix(int **matrix, int rows, int columns);


void power_array(int *arr, int len);


void remove_column(int **arr, int rows, int *columns, int index);


void remove_neg_columns(int **arr, int rows, int *columns);

void remove_columns_after_index(td_array *arr, int rows, int start_index);

#endif