#include <time.h>
#include "arrays.h"


void print_matrix_(int rows, int cols, float arr[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((int) arr[i][j] != arr[i][j]) {
                printf("%.1f\t", arr[i][j]);
            } else {
                printf("%.0f\t", arr[i][j]);
            }
        }
        printf("\n");
    }
}


float edit(int rows, int cols, float arr[rows][cols]) {

    int flag = false;
    int zero_i;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < 0) {
                flag = true;
                zero_i = j;
                break;
            }
        }
        if (flag) break;
    }

    if (flag) {
        for (int i = 0; i < cols; i++) {
            arr[i][zero_i] /= 2;
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

    float arr[rows][cols];

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

    arr[cols][rows] = edit(rows, cols, arr);

    printf("\n");
    print_matrix_(rows, cols, arr);

    return 0;
}

