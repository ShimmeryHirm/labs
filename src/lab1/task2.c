#include <stdio.h>

int main() {
    int x0, y0, x1, y1, x2, y2;

    printf("Input x0, y0:");
    int check = scanf("%d %d", &x0, &y0);
    if (check != 2) {
        printf("Wrong input!");
        return 0;
    }

    printf("Input x1, y1:");
    check = scanf("%d %d", &x1, &y1);
    if (check != 2) {
        printf("Wrong input!");
        return 0;
    }

    printf("Input x2, y2:");
    check = scanf("%d %d", &x2, &y2);
    if (check != 2) {
        printf("Wrong input!");
        return 0;
    }

    int r1 = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
    int r2 = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);

    if (r2 == r1) {
        printf("Point is on circle");
    } else {
        printf("Point is out circle");
    }

    return 0;
}
