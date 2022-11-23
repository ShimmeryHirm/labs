#include "sorts.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void neg_select_sort(int *arr, int len) {

    int min_i;

    for (int i = 0; i < len - 1; i++) {

        if (arr[i] >= 0) continue;

        min_i = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min_i])
                min_i = j;

        if (min_i != i)
            swap(&arr[min_i], &arr[i]);
    }
}

void character_shell_sort(int **arr, int rows, int cols, int (*c_func)(int *, int)) {

    for (int interval = rows / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < rows; i++) {

            int *temp = arr[i], j;
            for (j = i; j >= interval && (*c_func)(arr[j - interval], cols) < (*c_func)(temp, cols); j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

void neg_bubble_sort(int *arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        if (arr[i] >= 0) continue;

        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}