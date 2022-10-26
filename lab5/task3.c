#include "arrays.h"

int main() {

    int rows, cols;

    input(&rows, 1, INT_MAX, "Input rows:");
    input(&cols, 1, INT_MAX, "Input columns:");

    int **arr = (int **) malloc(rows * sizeof(int *));

    fill_matrix(arr, rows, cols);
    remove_neg_columns(arr, rows, &cols);
    print_matrix(arr, rows, cols);

    return 0;
}