#include <stdio.h>

int main() {
    int m;

    printf("Input m:");
    int check = scanf("%d", &m);
    if (!check) {
        printf("Wrong input!");
        return 0;
    }

    for (int n1 = 0; n1 <= 10; n1++) {
        for (int n3 = 0; n3 <= 10; n3++) {
            for (int n5 = 0; n5 <= 10; n5++) {
                if (n1 + n3 * 3 + n5 * 5 == m && n1 + n3 + n5 == 10) {
                    printf("Possible");
                    return 0;
                }
            }
        }
    }

    printf("Impossible");

    return 0;
};