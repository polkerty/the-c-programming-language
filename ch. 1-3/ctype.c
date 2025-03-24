#include <stdio.h>
#include <ctype.h>

void str_lower(char []);
void str_upper( char[]);

int main() {
    char x[1000] = "One step closter";
    printf("%s\n", x);
    str_lower(x);
    printf("%s\n", x);
    str_upper(x);
    printf("%s\n", x);
}

void str_lower( char s[]) {
    int i;
    for ( i = 0; s[i] != '\0' && (s[i] = tolower(s[i])); ++i)
        ;
}

void str_upper( char s[]) {
    int i;
    for ( i = 0; s[i] != '\0' && (s[i] = toupper(s[i])); ++i)
        ;
}