#include <stdint.h>

uint32_t sum(uint32_t a, uint32_t b) {
    while (b) {
        uint32_t sum = a ^ b;
        uint32_t carry = (a & b) << 1;
        a = sum;
        b = carry;        
    }
    return a;
}