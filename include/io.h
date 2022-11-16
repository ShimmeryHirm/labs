#include <stdio.h>
#include <stdlib.h>

#ifndef IO_H
#define IO_H

void input(int *var, int min, int max, char *str) {

    printf("%s", str);
    while (!scanf("%d", var) || (*var > max && max != INT_MAX) ||
           (*var < min && min != INT_MIN) || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}

#endif