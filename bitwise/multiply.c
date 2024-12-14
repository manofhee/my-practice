#include <stdio.h>
#include <stdint.h>

// brute force
uint64_t Add(uint64_t a, uint64_t b) {
    while (b) {
        uint64_t sum = a ^ b;
        uint64_t carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}


uint64_t Multiply(uint64_t x, uint64_t y) {
    uint64_t sum = 0;
    while (x) {
        if (x & 1) {
            sum = Add(sum, y);
        }
        x >>= 1;
        y <<= 1;
    }
    return sum;
}

uint64_t Multiply_bruteforce(uint64_t x, uint64_t y) {
    uint64_t sum = 0;
    while (y) {
        sum = Add(sum, x);
        y--;
    }
    return sum;
}


int main()
{
    uint64_t x = 10, y=66;
    // int i = 1, j = 6;
    printf("brute: x(%llu),y(%llu): %llu\n", x, y, Multiply_bruteforce(x, y));
    printf("shift: x(%llu),y(%llu): %llu\n", x, y, Multiply(x, y));
}