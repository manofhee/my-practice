#include <stdio.h>
#include <stdint.h>

// brute force
int64_t Reverse_bruteforce(int32_t x) {
    int64_t result = 0;
    while (x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

int main() {
    int32_t x = 42;
    printf("brute: x(%d): %lld\n", x, Reverse_bruteforce(x));
}