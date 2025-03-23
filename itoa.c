#include <stdio.h>
#include <stdlib.h>

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

void itoa(int n, char s[])
{
    int i, sign, least;
    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */
    i = 0;
    least = n - 1 > n ? 1 : 0;

    do
    {                                                      /* generate digits in reverse order */
        s[i++] = (least ? (~(n % 10)) + 1 : n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[20];
    for (int i = -__INT_MAX__ - 1; i < -__INT_MAX__ + 10; i++)
    {
        itoa(i, s);
        printf("%d %s\n", i, s);
    }
}
