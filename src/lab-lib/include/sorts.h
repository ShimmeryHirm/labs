
#ifndef SORTS_H
#define SORTS_H

void swap(int *a, int *b);

void neg_select_sort(int *arr, int len);

void neg_bubble_sort(int *arr, int len);

void character_shell_sort(int **arr, int rows, int cols, int (*c_func)(int *, int));

#endif