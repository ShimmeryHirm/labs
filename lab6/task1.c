#include "arrays.h"
#include "sorts.h"


int main() {

    int len;
    input(&len, 1, INT_MAX, "Input len:");

    int *arr = (int *) malloc(len * sizeof(int *));

    fill_array(arr, len);
    neg_select_sort(arr, len);
    print_row(arr, len);

    return 0;
}