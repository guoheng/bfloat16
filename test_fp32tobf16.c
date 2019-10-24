#include <stdio.h>

extern "C" float fp32tobf16(float x);

void print_hex(float x)
{
    int *p = (int*) &x;
    printf("%f=%x\n", x, *p);
}

int main()
{
    float a[] {1.2, 2.31, 3.46, 5.63};
    float bf_a;
    int i;

    for (i=0; i < 4; i++) {
        print_hex(a[i]);
        bf_a = fp32tobf16(a[i]);
        print_hex(bf_a);
    }

    return 0;
}
