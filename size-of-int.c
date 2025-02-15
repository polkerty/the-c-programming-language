#include <stdio.h>

int main() {
    unsigned int i = 1;
    int bits = 0;
    while (bits++, i > 0) {
        printf("[%d]: %u\n", bits, i);
        i <<= 1;
    }
}