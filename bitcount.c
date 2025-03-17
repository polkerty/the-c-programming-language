#include <stdio.h>
#include <stdlib.h>

int bitcount( int x);
void print_binary(unsigned int);

int main(int argc, char* argv[]) {

    int x, n;
    if ( argc < 2) {
        printf("Usage: ./bitcount x\n");
        return 1;
    }

    x = atoi(argv[1]);

    x = -40;



    print_binary(x);
    print_binary(x - 1);

    printf("Bitcount: %d\n", bitcount(x));

}

void print_binary(unsigned int x) {
    printf (" 0x");
    for ( int i = 31; i > -1; --i ) {
        printf("%c", (x & (1 << i) ? '1' : '0'));
    }
    printf(" = %d\n", x);
}
 
int bitcount(int x) {
    int n = 0;
    
    while ( x ) {
        n++;
        x &= x - 1;
        print_binary(x);
        print_binary(x - 1);

    }
    return n;
 }