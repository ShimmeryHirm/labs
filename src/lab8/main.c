#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int len;
    char *string;

    int max_word_len;
} str;

int str_len(const char *str) {
    int len = 0;
    while (*(str + len) != '\0') len++;
    return len;
}

int max_word_len(const char *str, int len) {

    int max = 0;
    int word_len = 0;

    for (int i = 0; i <= len; i++) {

        word_len++;

        if (str[i] == ' ' || str[i] == '\0') {
            if (word_len > max) max = word_len;
            word_len = 0;
        }
    }
    return max - 1;
}

void insert_sort(str *arr, int len) {
    for (int i = 1; i < len; i++) {
        str key = arr[i];
        int j;

        for (j = i - 1; j > 0 && arr[j].max_word_len < key.max_word_len; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {

    if (!(argc - 1)) {
        printf("Provide strings in args!");
        return 0;
    }

    str *word_list = calloc(argc - 1, sizeof(str));

    for (int i = 1; i < argc; i++) {
        word_list[i].len = str_len(argv[i]);
        word_list[i].string = calloc(word_list[i].len, sizeof(char));
        word_list[i].string = argv[i];
        word_list[i].max_word_len = max_word_len(argv[i], word_list[i].len);

    }
    printf("Strings from args and their length:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", word_list[i].string, word_list[i].max_word_len);
    }

    printf("\nStrings after sorting:\n");
    insert_sort(word_list, argc);

    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", word_list[i].string, word_list[i].max_word_len);
    }
    return 0;
}