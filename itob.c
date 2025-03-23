#include <stdlib.h>
#include <stdio.h>

void reverse(char s[])
{
    int i = 0, j = 0;
    char tmp;
    while (s[j] != '\0')
        ++j;
    for (--j; i < j; i++, j--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void itob(int n, char s[], int b) {


    int i = 0, remainder;
    char repr;
    int sign = n < 0 ? -1 : 1;
    if ( n < 0 ) n = -n;

    do {
        remainder = n % b;
        repr = remainder < 10 ? '0' + remainder : 'a' + (remainder - 10);
        s[i] = repr;
        i++;
        n /= b;

    } while ( n );

    if (sign < 0) s[i++] = '-';

    s[i] = '\0';

    reverse(s);


}

int main(int argc, char ** argv) {
    int n, b;
    char s[100];
    if ( argc != 3 ) {
        printf("Usage: %s NUMBER BASE\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    b = atoi(argv[2]);

    itob(n, s, b);

    printf("%d_%d = %s\n", n, b, s);

}