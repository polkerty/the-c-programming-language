#include <stdio.h>

void squeeze(char s[], char t[]);

int main() {
    char s[100];
    char t[100];
    char c;
    int i;

    // i/o
    while ( (c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    i = 0;
    while ( (c = getchar()) != '\n') {
        t[i++] = c;
    }
    t[i] = '\0';

    printf("%s\n", s);
    printf("%s\n", t);
    squeeze(s, t);
    printf("%s\n", s);
}

void squeeze(char s[], char t[]) {
    int i, j, k;
    for ( i = j = 0; s[i] != '\0'; ++i ) {
        for ( k = 0; t[k] != '\0'; ++k) {
            if ( s[i] == t[k]) {
                break;
            }
        }
        if ( t[k] == '\0' ) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}