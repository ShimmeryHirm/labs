#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    int rows, col;
    char mode;

    srand(time(NULL));

    printf("Input matrix rows:");
    while (!scanf("%d", &rows) || rows <= 0) {
        printf("Wrong rows, input again:");
        rewind(stdin);
    }

    printf("Input matrix columns:");
    while (!scanf("%d", &col) || col <= 0) {
        printf("Wrong columns, input again:");
        rewind(stdin);
    }

    float arr[rows][col];

    printf("Fill matrix random numbers? [y/n]");
    scanf(" %c", &mode);
    while (mode != 'y' && mode != 'v') {

        printf("Wrong answer, input again:");
        scanf(" %c", &mode);
        rewind(stdin);
    }


    if (mode == 'y') {
        printf("Generated array:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = rand() % 11;
                if (arr[i][j] < 3) {
                    arr[i][j] *= -1;
                }
                printf("%.0f ", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < rows; i++) {
            printf("Input %d elements of row %d:", col, i);
            for (int j = 0; j < col; j++) {
                while (!scanf("%f", &arr[i][j])) {
                    printf("Wrong elem, input again:");
                    rewind(stdin);
                }
            }
            printf("\n");
        }
    }
    int flag = 0;
    int zero_i;
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < col; j++) {


            if (arr[i][j] < 0) {
                flag = 1;
                zero_i = j;
                break;
            }
        }
        if (flag) {
            break;
        }


    }

    if (flag) {

        for (int i = 0; i < col; i++) {
            arr[i][zero_i] /= 2;
        }
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            if ((int)arr[i][j] != arr[i][j]) {
                printf("%.1f ", arr[i][j]);
            } else {
                printf("%.0f ", arr[i][j]);

            }

        }
        printf("\n");
    }


    return 0;
}