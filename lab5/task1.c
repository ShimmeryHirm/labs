# include "arrays.h"

int main() {

    int len = 5, *arr;

    fill_row(&arr, len * 2);
    power_row(arr, len);
    out_row(arr, len * 2);

    return 0;
}