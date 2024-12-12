#include <stdio.h>
#include <omp.h>
#include <math.h> 
#define N 10000 
int main()
{
    int a[N], b[N], c[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }

#pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            for (int i = 0; i < N; i++) {
                b[i] = a[i] * 2;
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                c[i] = (int)pow((float)a[i], 0.5f);
            }
        }
#pragma omp barrier
        printf("Last C is %d\n", c[N - 1]);
    }

    return 0;
}
