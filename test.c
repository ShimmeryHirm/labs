#include <stdio.h>

void print(int v) {
    printf("%d", v);
}

void func(void (*f)(int)) {
    for (int ctr = 0; ctr < 5; ctr++) {
        (*f)(ctr);
    }
}

int main() {


}