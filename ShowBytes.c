#include <stdio.h>
#include "csapp.h"

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    printf("\n");
    show_float(fval);
    printf("\n");
    show_pointer(pval);
}

int main()
{
//    int val = 12345;
//    test_show_bytes(val);
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));
}
