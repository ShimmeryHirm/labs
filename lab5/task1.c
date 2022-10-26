# include "arrays.h"

int main() {

    int len;
    input(&len, 1, 10, "Input len:");

    int *arr = (int *) malloc(len * 2 * sizeof(int *));

    fill_array(arr, len);
    power_array(arr, len);
    out_row(arr, len * 2);

    return 0;
}