#include <stdio.h>
#include <stdint.h>

// swap bits at index i and index j of given x (64bits)

// brute force
// int16_t SwapBits(uint64_t x, int i, int j)
// {
//     uint64_t index_i = x >> i & 0x1;
//     uint64_t index_j = x >> j & 0x1;

//     x = (x & ~(uint64_t)(0x1 << i)) | (index_j << i);
//     x = (x & ~(uint64_t)(0x1 << j)) | (index_i << j);

//     return x;
// }

// improved
int16_t SwapBits(uint64_t x, int i, int j)
{
    if (i == j)
        return x;

    if (((x >> i) & 0x1) != ((x >> j) & 0x1)) {
        uint64_t bitmask = (1 << i) | (1 << j);
        x ^= bitmask;
    }

    return x;
}


int main()
{
    uint64_t x = 73;
    int i = 1, j = 6;
    printf("x(%llu),i(%d),j(%d): %d\n",x,i,j, SwapBits(x, i, j));
}