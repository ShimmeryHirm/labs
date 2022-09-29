#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float abs_(float value) {
    return value * (float) ((value > 0) - (value < 0));
}


float rand_f() {

    return ((float) rand() / (float) (RAND_MAX)) * 50;

}

int main() {
    int len;
    char mode;

    srand(time(NULL));


    printf("Input array len:");
    while (!scanf("%d", &len) || len <= 0) {
        printf("Wrong len, input again:");
        rewind(stdin);
    }


    float arr[len];
    printf("Fill array random numbers? [y/n]");
    scanf(" %c", &mode);
    while (mode != 'y' && mode != 'n') {

        printf("Wrong answer, input again:");
        scanf(" %c", &mode);
        rewind(stdin);
    }


    if (mode == 'y') {
        printf("Generated array:");
        for (int i = 0; i < len; i++) {
            arr[i] = rand_f();
            printf(" %f", arr[i]);
        }
        printf("\n");
    } else {
        printf("Input %d elements:", len);
        for (int i = 0; i < len; i++) {
            while (!scanf("%f", &arr[i])) {
                printf("Wrong elem, input again:");
                rewind(stdin);
            }
        }
    }


    float max = abs_(arr[0]);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (max < abs_(arr[i])) {
            max = abs_(arr[i]);
            index = i;
        }
    }
    printf("Max value index: %d\n", index);


    float sum = 0;
    int pos_check = 0;
    for (int i = 0; i < len; i++) {
        if (pos_check) {
            sum += arr[i];
        }
        if (arr[i] > 0) {
            pos_check = 1;
        }
    }

    printf("Sum: %f", sum);


    return 0;
}