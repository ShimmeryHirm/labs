#include <time.h>
#include "arrays.h"


void print_matrix_(int rows, int cols, int arr[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        print_row(arr[i], cols);
        printf("\n");
    }
}


int find_min(int size, int arr[size][size]) {

    int center = size / 2;
    int min = arr[size - 1][size - 1];

    int k = 0;

    for (int j = size - 1; j >= center; j--) {

        for (int i = k; i < size - k; i++) {

            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
        k++;
    }
    return min;
}


int main() {

    srand(time(NULL));

    int size, min;
    char mode;

    input(&size, 1, 100, "Input size:");

    int arr[size][size];

    printf("Fill matrix random numbers? [y/n]");
    while (!scanf(" %c", &mode) || (mode != 'y' && mode != 'n') || getchar() != '\n') {
        printf("Wrong answer, input again:");
        rewind(stdin);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mode == 'y') {
                arr[i][j] = rand() % 20 - 10;
            } else {
                printf("Input %d elements of row %d:", size, i + 1);
                input(&arr[i][j], INT_MIN, INT_MAX, "");
            }
        }
    }

    printf("Input array:\n");
    print_matrix_(size, size, arr);

    min = find_min(size, arr);

    printf("Result: %d", min);

    return 0;
}
