#include <stdio.h>

void expand(char in[], char out[]);

int main()
{
    // get input
    char in[100], out[1000];
    char c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        in[i] = c;
        i++;
    }
    in[i] = '\0';

    expand(in, out);
    printf("%s = %s\n", in, out);
}

void expand(char in[], char out[])
{
    int i = 0, j = 0, n = 0;
    char lead = 0;
    int expansion_open = 0;

    // determine length of string,
    // so we can detect trailing -
    while (in[n] != '\0')
        n++;

    for (; in[i] != '\0'; i++)
    {
        if (in[i] == '-')
        {
            if (i == 0 || i == n - 1)
            {
                // A literal dash
                out[j++] = '-';
            }
            else
            {
                expansion_open = 1;
            }
        }
        else if (!expansion_open)
        {
            // print the current character out directly
            // in case we're both the end and beginning
            // of an expansion
            out[j++] = in[i];
            lead = in[i] + 1;
        }
        else if (expansion_open)
        {
            // We just saw a -, and we want to expand on it
            while (lead <= in[i])
            {
                out[j++] = lead++;
            }
            expansion_open = 0;
        }
    }
    out[j] = '\0';
}