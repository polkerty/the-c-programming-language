#include <stdio.h>

int main() {
    int blanks = 0, newlines = 0, tabs = 0;
    int c;
    while ( (c = getchar()) != EOF ) {
        switch(c) {
            case '\t':
                tabs++;
                break;
            case '\n':
                newlines++;
                break;
            case ' ':
                blanks++;
                break;
        }
    }
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
}