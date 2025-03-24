#include <stdio.h>

#define MAX_LEN 100

int htoi(char[]);

int main() {
    int c, i, res;
    char h[MAX_LEN];

    for ( i = 0; (i < MAX_LEN - 1) && (c = getchar()) != EOF; ++i ) {
        if ( c == '\n') break;
        h[i] = c;
    }
    h[i] = '\0';

    res = htoi(h);
    printf("%s = %u\n", h, res);
    

}

int htoi(char hex[]) {
    int pos;
    long res = 0;
    int len;
    
    // get length for convenience
    for ( pos = 0, len = 0; hex[pos] != '\0'; ++pos, ++len);
    pos = 0;

    // optionally eat prefix
    if ( len > 2 && hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        pos = 2;

    for ( ; pos < len; ++pos ) {

        res *= 16;
        if ( hex[pos] >= '0' && hex[pos] <= '9') {
            res += hex[pos] - '0';
        } else if ( hex[pos] >= 'a' && hex[pos] <= 'f') {
            res += hex[pos] - 'a' + 10;
        } else if ( hex[pos] >= 'A' && hex[pos] <= 'F') {
            res += hex[pos] - 'A' + 10;
        } else {
            // undefined behavior; do nothing, I guess?
        }
    }

    return res;

}