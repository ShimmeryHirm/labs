#include <stdio.h>

float pow_(float num, int power) {

    if (power == 0)
        return 1;

    if (power == 1)
        return num;

    return num * pow_(num, power - 1);
}

int fact(int n) {

    if (n == 0) {
        return 1;
    } else {
        return (n * fact(n - 1));
    }
}

int main() {
    float angle;

    printf("Input angle:");
    int check = scanf("%f", &angle);
    if (!check) {
        printf("Wrong input!");
        return 0;
    }

    angle = angle * 3.14 / 180.0;

    float sin = 0;
    for (int i = 0; i < 10; i++) {
        sin += pow_(-1, i) * pow_(angle, 2 * i + 1) / fact(2 * i + 1);
    }

    float cos = 0;
    for (int i = 0; i < 10; i++) {
        cos += pow_(-1, i) * pow_(angle, 2 * i) / fact(2 * i);
    }

    printf("ctg=%f\n", cos / sin);

    return 0;
}