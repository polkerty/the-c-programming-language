/* This program removes comments 
 * from a C program. 
 * 
 * It handles both slash-star and slash-slash style comments.
 * 
 * This is a simple recursive-descent parser.
 */

#include <stdio.h>

void consume_program();
void consume_string();
void consume_slash_star();
void consume_slash_slash();



int main() {
    consume_program();
}

void consume_program() {
    int c;
    /*
        State is implicitly tracked by the "consumer" currently running..
        We can assume, for example, that we're not currently consuming a comment,
        or else we'd be in a comment consumer.  
    */
    while(1) {
        c = getchar(); // A streaming solution
        if ( c == EOF ) return;
        else if (c == '/' ) { // could be a comment start!
            c = getchar();
            if ( c == EOF ) {
                printf("/"); // for the slash we previously read (although I don't think a valid C program can end with a slash)
                return;
            } else if ( c == '*' ) { // slash-star, comment start
                consume_slash_star();
            } else if ( c == '/' ) { // slash-slash, also a comment start
                consume_slash_slash();
            } else {
                printf("/%c", c); // not a comment! print it out. 
                // NOTE: it's impossible for the second char to itself be the first char of a comment,
                // since we know it's not a /.
            }
        } else if ( c == '"' ) { // A comment
            printf("%c", c);
            consume_string();
        } else {
            // Since we didn't start a comment or a string, just print the character out.
            printf("%c", c);
        }
    }
}

void consume_string() {
    int c;
    int escaped = 0;
    int was_escaped = 0;
    int done = 0;
    // Assume the initial `"` has already been consumed by our caller.
    while (1) {
        c = getchar();
        was_escaped = escaped; // save the value so we can check it to clear later

        if ( c == EOF ) {
            // this is not a valid program, but just return to avoid crashing
            return; 
        } else if ( c == '\\') {
            // If we are not, ourselves, escaped, then launch the escape sequence
            if ( !escaped ) {
                escaped = 1;
            }
        } else if ( c == '"') {
            // Is this actually the end of the string?
            if ( !escaped ) {
                done = 1; // don't return here because we still need to print out the char
            }
        } else {
            // nothing to do.
        }

        printf("%c", c);
        if ( was_escaped ) {
            escaped = 0;
        }
        if ( done ) {
            break;
        }
    }

}

void consume_slash_star() {
    int c, prev_star;
    // assume we've already parsed the /*

    while (1) {
        prev_star = 0;
        /* Note: we don't use look-ahead in this program, but we need to handle
            the case where a slash-star comment ends with star-star-slash, as here. 

            Therefore, we need to greedily consume "*"'s. 
        **/
       while ( (c = getchar()) == '*') prev_star = 1;
       if ( prev_star && c == '/') {
            // There was (at least one) preceding *, and we just read a /,
            // so we're done.
            return;
       }
       // We read at least one character, and it is not part of a terminating production,
       // so continue.

    }
    
}

void consume_slash_slash() {
    int c;

    while(1) {
        // we've already read the //-part of the comment.
        c = getchar();
        if ( c == '\n') {
            // O.K., we're done!
            printf("\n");
            return;
        }
    }
}


// a tricky test case
char mysterious_string/*ignore me!*/[] = "This is a /*string*/ that \" // appears to contain comments, but does not.";
