#include <string.h>
#include <stdio.h>

void reverse(char buf[]) {
    int i, j;
    char tmp;

    i = 0;
    j = strlen(buf) - 1;

    while(i < j) {
        tmp = buf[i];
        buf[i] = buf[j];
        buf[j] = tmp;
        i++;
        j--;
    }

}