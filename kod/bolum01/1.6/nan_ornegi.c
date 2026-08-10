#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0.0 / 0.0;                 /* NaN uretir */
    printf("x = %f\n", x);                /* "x = nan" */
    printf("x == x: %d\n", x == x);       /* 0 (yanlis!) */
    printf("isnan(x): %d\n", isnan(x));   /* 1 (dogru yontem) */
    return 0;
}
