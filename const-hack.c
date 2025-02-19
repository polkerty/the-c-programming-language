#include <stdio.h>

int main() {

    char before_char = 0;
    const char my_arr[100] = "you can have your space, cowboy";

    printf("initial value: %s\n", my_arr);

    *(&before_char + 1) = 'Y';

    printf("value afterwards: %s\n", my_arr);
}