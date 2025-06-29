#include <stdio.h>

#define HARMONIC_MEAN(X, Y) (1.0 / (((1.0 / (X)) + (1.0 / (Y))) / 2.0))

int main(void) {
    

    printf("%f\n", HARMONIC_MEAN(2.5, 1.0 / 2.5));


    return 0;
}