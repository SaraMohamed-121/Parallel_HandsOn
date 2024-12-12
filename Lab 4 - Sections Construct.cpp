#include <stdio.h>
#include <omp.h>

#define N 100
int main() 
{
    int i;
    float a[N], b[N], c[N], d[N];
    for (i = 0; i < N; i++) {
        a[i] = i * 1.5;
        b[i] = i + 22.35;
    }
    omp_set_num_threads(10);
#pragma omp parallel shared(a, b, c, d) private(i)
    {
#pragma omp sections nowait
        {
#pragma omp section
            for (i = 0; i < N; i++) {
                c[i] = a[i] + b[i];
            }

#pragma omp section
            for (i = 0; i < N; i++) {
                d[i] = a[i] * b[i];
            }
        } 
    } 

    for (i = 0; i < 10; i++) {
        printf("c[%d] = %f, d[%d] = %f\n", i, c[i], i, d[i]);
    }
    return 0;
}
