#include <stdio.h>
#include <stdint.h>

// The parity of a binary word is 1 if the number of 1s in the word is odd; otherwise, it is 0
int16_t Parity(uint64_t x) {
    int16_t parity = 0;
    while (x) {
        if (x & 1)
            parity ^= 0x1;
        x >>= 1;
    }
    return parity;
}

int main() {
    uint64_t x = 16;
    printf("%llu: %d\n", x, Parity(x));
}