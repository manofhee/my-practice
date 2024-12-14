#include <stdio.h>
#include <stdint.h>

// brute force
uint64_t Reverse(uint64_t x) {
    uint64_t result = 0;
    for(int i=0; i<64; i++) {
        result |= (uint64_t)((x >> i) & 0x1) << (63-i);
    }
    return result;
}

// lookup table
uint16_t create_lookup(uint16_t x) {
    uint16_t result = 0;
    for(int i=0; i<16; i++) {
        result |= (uint16_t)((x >> i) & 0x1) << (15-i);
    }
    return result;
}

// 2^4 = 16
// 2^6 = 64
// 2^8 = 256
// 2^16 = 

uint64_t Reverse_lookup(uint64_t x) {
    uint64_t result = 0;
    uint16_t lookup[256*256];
    for(int i=0; i<256*256; i++) {
        lookup[i] = create_lookup(i);
    }
    result = ((uint64_t)lookup[x & 0xFFFF] << 48) | 
        ((uint64_t)lookup[(x >> 16) & 0xFFFF] << 32) | 
        ((uint64_t)lookup[(x >> 32) & 0xFFFF] << 16) | 
        ((uint64_t)lookup[(x >> 48) & 0xFFFF]);
    return result;
}

int main()
{
    uint64_t x = 0x505;
    // int i = 1, j = 6;
    printf("brute: x(0x%llx): 0x%llx\n", x, Reverse(x));
    printf("lookup: x(0x%llx): 0x%llx\n", x, Reverse_lookup(x));
}