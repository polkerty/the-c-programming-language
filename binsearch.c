#include <stdio.h>

int binsearch(int x, int v[], int n);
// int binsearch2(int x, int v[], int n);

int main()
{
    int n = 1000000;
    int v[n];
    long total = 0; // to avoid gcc throwing the result away

    for ( int i = 0; i < n; ++i ) v[i] = i + 1;


    for ( int i = 0; i < n; ++i ) {
        // printf("Position of %d in array is %d\n", v[i], binsearch(v[i], v, n));
        total += binsearch(v[i], v, n);
    }

    long expected = (long)n * (n - 1) / 2;

    printf("OK: %d, GOT: %ld, EXPECTED: %ld\n", 
        total == expected,
        total,
        expected    
    );

}

int binsearch(int x, int v[], int n)
{

    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}