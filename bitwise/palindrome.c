#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// check if a number is one which reads the same forwards and backwards. e.g., 12321

int CountDigits(int32_t x) {
    int count = 0;
    while (x) {
        count++;
        x /= 10;
    }
    return count;
}

bool CheckPalindrome(int32_t x) {
    bool result = true;
    int n = CountDigits(x);
    int msd_mask = (int)pow(10, n-1);
    for (int i=0; i< n/2; i++) {
        if (x / msd_mask != x % 10)
            return false;
        x %= msd_mask;
        x /= 10;
        msd_mask /= 100;
    }
    return result;
}

int main() {
    int32_t x = 123212;
    printf("check: x(%d): %d\n", x, CheckPalindrome(x));
}


