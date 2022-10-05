
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    int size;
    char mode;

    srand(time(NULL));

    printf("Input matrix size:");
    while (!scanf("%d", &size) || size <= 0) {
        printf("Wrong rows, input again:");
        rewind(stdin);
    }


    int arr[size][size];

    printf("Fill matrix random numbers? [y/n]");
    scanf(" %c", &mode);
    while (mode != 'y' && mode != 'v') {

        printf("Wrong answer, input again:");
        scanf(" %c", &mode);
        rewind(stdin);
    }


    if (mode == 'y') {
        printf("Generated array:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                arr[i][j] = rand() % 10;
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < size; i++) {
            printf("Input %d elements of row %d:", size, i);
            for (int j = 0; j < size; j++) {
                while (!scanf("%d", &arr[i][j])) {
                    printf("Wrong elem, input again:");
                    rewind(stdin);
                }
            }
            printf("\n");
        }
    }
    int center = size / 2;
    int sum = 0;

    int k = 0;
    for (int j = size - 1; j >= center; j--) {

        for (int i = k; i < size - k; i++) {
            sum += arr[i][j];
        }
        k++;
    }

    printf("Result: %d", sum);

    return 0;
}