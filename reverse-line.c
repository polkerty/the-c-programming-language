#include <stdio.h>

#define MAX_LINE 1000

void reverse(char[]);
int get_line(char[], int);

int main() {
    int c;
    char buff[MAX_LINE];
    
    while ( get_line(buff, MAX_LINE) != 0) {
        reverse(buff);
        printf("%s", buff);
    }


}

void reverse(char s[]) {
    int len, iter, tmp;

    // 1. Determine the length of the string
    for ( len = 0; s[len] != '\0'; ++len)
        ;

    // 2. Reverse the string
    for (iter = 0; iter < len / 2; ++iter) {
        tmp = s[iter];
        s[iter] = s[len - iter - 1];
        s[len - iter - 1] = tmp;
    }
}

int get_line(char buff[], int max_len) {
    int c, len;

    len = 0;

    for( c = getchar(), len = 0; c != EOF && len < max_len - 1; c = getchar(), len++) {
        buff[len] = c;
        if ( c == '\n') {
            ++len;
            break;
        }
    }

    buff[len] = '\0';
    // printf("[get_line] %s %d\n", buff, len);
    return len;

}