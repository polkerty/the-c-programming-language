#include <stdio.h>

#define IN 0
#define OUT 1
#define MAX_LEN 10

int main() {

    int hist[MAX_LEN + 1];

    int state = IN;
    int c, i, j;
    int cur_count = 0;

    int max_size = 0; 

    // 0. clear counters
    for (i = 0; i <= MAX_LEN; ++i ) hist[i] = 0;

    // 1. Produce histogram
    while ( (c = getchar()) != EOF) {
        int is_letter_or_number = (c >= 'A' && c <= 'Z') ||
             (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');   
        if ( is_letter_or_number && state == OUT ) {
            // starting a new word
            state = IN;
            cur_count = 1;
        } else if ( is_letter_or_number && state == IN ) {
            // in a word
            ++cur_count;
        } else if ( !is_letter_or_number && state == IN ) {
            // end word
            if ( cur_count > MAX_LEN ) {
                cur_count = MAX_LEN;
            }
            hist[cur_count] ++;
            if ( cur_count > max_size) {
                max_size = cur_count;
            }
            state = OUT;
            cur_count = 0;
        } else if ( !is_letter_or_number && state == OUT ) {
            // nothing to do 
        }
        printf("char: %c, cur count: %d, is_letter_or_number: %d\n", 
            c, cur_count, is_letter_or_number);
    }

    // 2. Draw vertical histogram
    for ( i = 0; i < max_size; ++i ) {
        for ( j = 1; j <= MAX_LEN; ++j ) {
            if ( i >= max_size - hist[j] ) {
                printf(" ##\t");
            } else {
                printf("   \t");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= MAX_LEN; ++i) {
        printf("==========");
    }
    printf("\n");
    for ( i = 1; i <= MAX_LEN; ++i ) {
        printf("%2d\t", i);
    }
    printf("\n");


}