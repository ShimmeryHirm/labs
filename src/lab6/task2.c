#include "arrays.h"
#include "sorts.h"
#include "input.h"

int character(const int *row, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (!((i + 1) % 2)) sum += row[i];
    }
    return sum;
}

int main() {
    int rows = 4, cols = 3;

    input(&rows, 1, INT_MAX, "Input rows:");
    input(&cols, 1, INT_MAX, "Input columns:");

    int **arr = (int **) malloc(rows * sizeof(int *));

    fill_matrix(arr, rows, cols);

    character_shell_sort(arr, rows, cols, (int (*)(int *, int)) character);
    print_matrix(arr, rows, cols);

    return 0;
}