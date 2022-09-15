#include <stdio.h>


int main() {
    int a, b, c, n;

    printf("Input a, b, c, N");

    scanf("%d %d %d %d", &a, &b, &c, &n);


    printf("N is divisor for ");

    if (!(a % n)) {
        printf("a, ");
    }
    if (!(b % n)) {
        printf("b, ");
    }
    if (!(c % n)) {
        printf("c");
    }

    return 0;
}
