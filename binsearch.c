#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);
// int binsearch2(int x, int v[], int n);

int main()
{
    int n = 10000000;
    int *v = malloc(sizeof(int) * n);
    long total = 0; // to avoid gcc throwing the result away

    printf("setting up array\n");

    for ( int i = 0; i < n; ++i ) v[i] = i + 1;

    printf("testing binary search...\n");
    for ( int i = 0; i < n; ++i ) {
        // printf("Position of %d in array is %d\n", v[i], binsearch(v[i], v, n));
        total += binsearch(v[i], v, n);
    }

    printf("Total iters: %ld\n", 
        total    
    );

}

int binsearch(int x, int v[], int n)
{

    int low, high, mid;
    low = 0;
    high = n - 1;
    int iters = 0;
    while (low <= high)
    {
        iters ++;
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return iters;
    }
    return iters; /* no match */
}