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

    int arr[rows][col + 1];

    printf("Fill matrix random numbers? [y/n]");
    scanf(" %c", &mode);
    while (mode != 'y' && mode != 'v') {

        printf("Wrong answer, input again:");
        scanf(" %c", &mode);
        rewind(stdin);
    }


    if (mode == 'y') {
        printf("\nGenerated array:\n");
        for (int i = 0; i < rows; i++) {
            arr[i][col] = 0;
            for (int j = 0; j < col; j++) {
                arr[i][j] = rand() % 11;
                arr[i][col] += arr[i][j];
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < rows; i++) {
            arr[i][col] = 0;

            printf("Input %d elements of row %d:", col, i + 1);
            for (int j = 0; j < col; j++) {
                while (!scanf("%d", &arr[i][j])) {
                    printf("Wrong elem, input again:");
                    rewind(stdin);
                }
                arr[i][col] += arr[i][j];

            }
            printf("\n");
        }
    }


    int max, max_i, tmp[col + 1];
    for (int k = 0; k < rows; k++) {
        max = arr[k][col];
        max_i = k;


        for (int i = k; i < rows; i++) {
            if (arr[i][col] > max) {
                max  = arr[i][col];
                max_i = i;
            }
        }


        for (int i = 0; i <= col; i++) {
            tmp[i] = arr[max_i][i];
        }


        for (int i = max_i; i >= k; i--) {
            for (int j = 0; j <= col; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }


        for (int i = 0; i <= col; i++) {
            arr[k][i] = tmp[i];
        }

    }

    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}