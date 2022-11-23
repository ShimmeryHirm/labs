#include <stdio.h>

int main() {
    double s = 20, t;
    int v_walk1 = 2, v_walk2 = 3, v_shmel = 5, shmel_direct = 1;

    while (s > 0.00001) {

        if (shmel_direct) {
            t = s / (v_shmel + v_walk2);
        } else {
            t = s / (v_shmel + v_walk1);
        }

        shmel_direct = !shmel_direct;
        s = s - t * (v_walk1 + v_walk2);

        printf("%.3f m\n", v_shmel * t * 1000);
    }
    return 0;
}