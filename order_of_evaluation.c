#include <stdio.h>


int main() {
    int cnt = 100;
    int bubbles[cnt];
    int i = 0;
    while ( i < cnt) { 
        bubbles[i] = i++;
    }

    for (i = 0; i < cnt; ++i ) {
        printf("bubbles[%d]\t=\t%d\n", i, bubbles[i]);
    }
}