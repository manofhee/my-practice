#include <stdio.h>
#include <stdint.h>

double Power(double x, int32_t y) {
    double result = 1;
    if (y == 0) {
        return 1.0;
    }
    result = x;

    while (y > 1) {
        result *= x;
        y--;
    }
    return result;
}

int main()
{
    double x = 2.0;
    uint64_t y = 5;
    printf("brute: x(%lf),y(%llu): %lf\n", x, y, Power(x, y));
}