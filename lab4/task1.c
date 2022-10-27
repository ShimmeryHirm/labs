#include <time.h>
#include "arrays.h"


int sum(const int *row, int len) {

    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (!(row[i] % 2) && row[i] > 0)
            sum += row[i];

    }
    return sum;
}


void print_matrix_(int rows, int cols, int arr[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        print_row(arr[i], cols);
        printf("\n");
    }
}


int find_min(int rows, int cols, int arr[rows][cols]) {

    int max, max_i, tmp[cols + 1];
    for (int k = 0; k < rows; k++) {
        max = sum(arr[k], cols);
        max_i = k;
        for (int i = k; i < rows; i++) {
            if (sum(arr[i], cols) > max) {
                max = arr[i][cols];
                max_i = i;
            }
        }
        for (int i = 0; i < cols; i++) {
            tmp[i] = arr[max_i][i];
        }
        for (int i = max_i; i >= k; i--) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }
        for (int i = 0; i < cols; i++) {
            arr[k][i] = tmp[i];
        }
    }
    return arr[cols][rows];
}


int main() {

    srand(time(NULL));

    int rows, cols;
    char mode;

    input(&rows, 1, 100, "Input rows:");
    input(&cols, 1, 100, "Input columns:");

    int arr[rows][cols];

    printf("Fill matrix random numbers? [y/n]");
    while (!scanf(" %c", &mode) || (mode != 'y' && mode != 'n') || getchar() != '\n') {
        printf("Wrong answer, input again:");
        rewind(stdin);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mode == 'y') {
                arr[i][j] = rand() % 20 - 10;
            } else {
                printf("Input %d elements of row %d:", cols, i + 1);
                input(&arr[i][j], INT_MIN, INT_MAX, "");
            }
        }
    }

    printf("Input array:\n");
    print_matrix_(rows, cols, arr);

    arr[cols][rows] = find_min(rows, cols, arr);

    printf("\n");
    print_matrix_(rows, cols, arr);

    return 0;
}