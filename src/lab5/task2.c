#include "arrays.h"
#include "input.h"

int main() {

    int rows, k;

    input(&rows, 1, INT_MAX, "Input rows:");
    input(&k, 0, INT_MAX, "Input K:");

    td_array *arr = (td_array *) (int **) malloc(rows * sizeof(td_array *));
    fill_2d_array(arr, rows);

    printf("In matrix:\n");
    print_2d_array(arr, rows);

    remove_columns_after_index(arr, rows, k);

    printf("Result matrix:\n");
    print_2d_array(arr, rows);

    return 0;
}