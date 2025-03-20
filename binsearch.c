#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(int argc, char **argv)
{

    if (argc < 3)
    {
        printf("Usage: ./binsearch n v\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int version = atoi(argv[2]);

    int *v = malloc(sizeof(int) * n);
    long total = 0; // to avoid gcc throwing the result away

    printf("setting up array\n");

    for (int i = 0; i < n; ++i)
        v[i] = i + 1;

    printf("testing binary search...\n");
    if (version == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            total += binsearch(v[i], v, n);
        }
    }
    else if (version == 2)
    {
        for (int i = 0; i < n; ++i)
        {
            total += binsearch2(v[i], v, n);
        }
    }
    else
    {
        printf("Version must be either 1 or 2\n");
    }

    printf("Total iters: %ld\n",
           total);
}

int binsearch(int x, int v[], int n)
{

    int low, high, mid;
    low = 0;
    high = n - 1;
    int iters = 0;
    while (low <= high)
    {
        iters++;
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

int binsearch2(int x, int v[], int n)
{

    int low, high, mid;
    low = 0;
    high = n - 1;
    int iters = 0;
    while (low + 1 < high )
    {
        // printf("[%d]\t[%d\t%d]\n", x, low, high);
        iters++;
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }
    if ( v[low] == x ) {
        // 
    } else if ( v[high] == x ) {
        //
    } else {
        printf("[%d]\tnot found!\n", x);
    }

    return iters;
}