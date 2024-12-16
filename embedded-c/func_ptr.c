typedef int(*Func_t)(int, int);
int add(int a, int b);
int multiply(int a, int b);

Func_t op = add;
op = add;

Func_t operations[2] = {add, multiply};

