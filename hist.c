#include <stdio.h>

int main() {
    int hist[265];
    int c, i;
    for ( i =0; i < 256; ++i ) {
        hist[i] = 0;
    }
    while ((c = getchar())!=EOF) {
        hist[c]++;
    };
    for ( i=65; i < 256; ++i ) {
        printf("[%c][%3d]: %3d\n", i, i, hist[i]);
    }
}