#include <stdio.h>
#include <stdint.h>

// int16_t CountBits(uint32_t x)
// {
//     int n = sizeof(uint32_t) * 8;
//     int16_t result = 0;
//     for(int i=0; i<n; i++) {
//         if ((x>>i) & 0x1)
//             result++;
//     }
//     return result;
// }

int16_t CountBits(uint32_t x)
{
    int16_t result = 0;
    while (x) {
        result += x & 1;
        x >>= 1;
    }
    return result;
}

int main()
{
    uint32_t x = 15;
    printf("%u: %d\n",x, CountBits(x));
}