#include <stdint.h>

uint16_t sum(uint8_t a, uint8_t b) {
    while (b != 0) {
        int sum = a ^ b;
        int carry = (a & b) << 1;

        a = sum;
        b = carry;
    }
    return a;
}

void main() {
    uint8_t num1 = 12, num2 = 5;
    int result = sum(num1, num2);
    print("sum: %d", result);
    return 0;
}


int sum(int a, int b) {
    return a+b;
}

typedef int(Func_t)(int , int);
Func_t* pfunc = sum;


