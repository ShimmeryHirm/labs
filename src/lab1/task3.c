#include <stdio.h>

int main() {
    int a, b, c, n;

    printf("Input a, b, c, N");

    int check = scanf("%d %d %d %d", &a, &b, &c, &n);
    if (check != 4) {
        printf("Wrong input!");
        return 0;
    }

    printf("N is divisor for ");

    if (!(a % n)) {
        printf("a ");
    }
    if (!(b % n)) {
        printf("b ");
    }
    if (!(c % n)) {
        printf("c");
    }

    return 0;
}
