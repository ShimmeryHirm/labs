#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "strings.h"


void task1(int cnt) {
    printf("%d", cnt);
}

void task2(int cnt) {
    if (cnt) printf("True"); else printf("False");
}

void run_task(int (*func)(int), int cnt) {
    func(cnt);
}

int main() {

    printf("Input string:");
    char *string = (char *) calloc(1, 1);
    gets(string);

    printf("Input substring:");
    char *substring = (char *) calloc(1, 1);
    gets(substring);

    int cnt = count_substrings(string, substring);

    while (1) {
        printf("\nTasks:\n1. Count substrings in string\n2. Check if substring in string\n0. Exit\n\n");

        int task;
        input(&task, 0, 2, "Input task:");

        if (!task) break;
        printf("\n");

        if (task == 1) run_task((int (*)(int)) task1, cnt);
        else run_task((int (*)(int)) task2, cnt);

        printf("\n");
    }
    return 0;
}