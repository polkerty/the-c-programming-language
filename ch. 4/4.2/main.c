#include <ctype.h>
#include <stdio.h>

// Convert a string into a floating-point number.
double atof( char s[]) {
    int i = 0;
    double val = 0.0;
    int sign;
    double pow = 1.0;
    int expsign;
    int exp = 0;

    // eat whitespace
    while(isspace(s[i])) i++;

    // sign
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+' ) i++;


    // construct first part of double
    while(isdigit(s[i])) {
        val = 10.0 * val + (s[i] - '0');
        i++;
    }

    // period
    if ( s[i] == '.' ) i++;

    // fractional part
    while(isdigit(s[i])) {
        val = 10.0 * val + (s[i] - '0');
        pow = pow * 10.0;
        i++;
    }

    // exponential part
    if (s[i] == 'e' || s[i] == 'E') {
        
        i++;
        expsign = s[i] == '-' ? -1 : 1;
        if ( s[i] == '-' || s[i] == '+') i++;
        while(isdigit(s[i])) {
            exp = 10 * exp + (s[i] - '0');
            i++;
        }

    }
    
    double ans = sign * val / pow;
    while ( exp > 0 ) {
        ans = expsign > 0 ? ans * 10 : ans / 10;
        exp--;
    }

    return ans;

}


int main(int argc, char** argv) {
    if ( argc != 2 ) {
        printf("Usage: %s number", argv[0]);
    }

    double out = atof(argv[1]);
    printf("%s = %.12f\n", argv[0], out);
}