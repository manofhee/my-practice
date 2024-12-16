#include <stdio.h>
#include <stdint.h>

// swap bits at index i and index j of given x (64bits)

// brute force
uint64_t test(uint64_t x)
{
    return x;
}


int main()
{
    uint64_t x = 73;
    int i = 1, j = 6;
    printf("brute: x(%llu): %llu\n", x, test(x));
    printf("improved: x(%llu): %llu\n", x, test(x));
}