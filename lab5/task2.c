#include "arrays.h"

int main() {

    int rows, k, max_column = 0;

    input(&rows, 1, INT_MAX, "Input rows:");
    input(&k, 0, INT_MAX, "Input K:");

    int **arr = (int **) malloc(rows * sizeof(int *));

    fill_2d_array(arr, rows, &max_column);

    printf("Current matrix:\n");
    print_matrix(arr, rows, max_column, true);

    for (int i = max_column - 1; i >= k; i--) {
        remove_column(arr, rows, &max_column, i);
    }

    printf("Result matrix:\n");
    print_matrix(arr, rows, max_column, true);

    return 0;
}