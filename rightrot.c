#include <stdio.h>
#include <stdlib.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main(int argc, char* argv[]) {

    unsigned x, n;
    if ( argc < 3) {
        printf("Usage: ./rightrot x n\n");
        return 1;
    }

    x = atoi(argv[1]);
    n = atoi(argv[2]);

    printf("x: %u %x, n: %u %x, x <r> n: %u %x\n", 
        x, x,
        n, n, 
        rightrot(x, n), rightrot(x, n)
    );


}

unsigned int rightrot(unsigned int x, unsigned int n) {
    unsigned int y = 0;
    unsigned int pos = 0;
    unsigned int nbits = 0;
    unsigned int ones = ~0;
    unsigned int target_pos;
    // how many bits?
    while (ones) { ++nbits; ones >>= 1; }
    
    // We just have to move the 1-bits into the right spots in y.

    while (x) {
        if ( x & 1 ) {
            if ( n < pos ) {
                y |= 1 << (pos - n);
            } else {
                y |= 1 << (pos + nbits - n);
            }
        }
        x >>= 1;
        pos++;
    }

    return y;
}
 