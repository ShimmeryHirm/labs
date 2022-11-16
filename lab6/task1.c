#include "arrays.h"
#include "sorts.h"
#include <time.h>
#include <mem.h>

#define start_timer(X) clock_t X = clock()
#define stop_timer(X) printf("%s completed for %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)


int main() {

    int len;
    input(&len, 1, INT_MAX, "Input len:");

    int *arr = (int *) malloc(len * sizeof(int *));
    int *arr_copy = (int *) malloc(len * sizeof(int *));;

    fill_random_array(arr, len, 1000);
    memcpy(arr_copy, arr, len * sizeof(int *));

    start_timer(select_sort);
    neg_select_sort(arr, len);
    stop_timer(select_sort);

    start_timer(bubble_sort);
    neg_bubble_sort(arr_copy, len);
    stop_timer(bubble_sort);

    print_row(arr, len);

    return 0;
}