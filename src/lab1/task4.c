#include <stdio.h>

int strcmp_(char *s1, char *s2) {
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }

    return !(s1[i] - s2[i]);
}

int main() {
    char dis[999];

    printf("Input discipline:");
    scanf("%s", dis);

    if (strcmp_(dis, "Culturology") || strcmp_(dis, "Informatics")) {
        printf("Zachet");
    } else if (strcmp_(dis, "Foreign language") || strcmp_(dis, "Maths")) {
        printf("Exam, zachet");
    } else if (strcmp_(dis, "Economy")) {
        printf("Exam");
    } else {
        printf("Not found");
    }
}