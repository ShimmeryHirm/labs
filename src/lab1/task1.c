# include <stdio.h>
# include <math.h>

int main() {
    float a;

    printf("Input a:");
    int check = scanf("%f", &a);
    if (!check) {
        printf("Wrong input!");
        return 0;
    }

    double s = sqrt(3) * a * a / 4.0;
    double h = sqrt(3) * a / 2.0;

    printf("S=%.3lf\nh=%.3lf", s, h);

    return 0;
}

