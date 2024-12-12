#include <stdio.h>
#include <omp.h>

#define N 10000  
int main()
{
    int a[N], sum = 0;
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;  
    }

    double start_time = omp_get_wtime();  

#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (a[i] % 7 == 0) {
#pragma omp atomic
            sum++;  
        }
    }

    double end_time = omp_get_wtime();  

    printf("The number of found divisible(s) is %d\n", sum);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}
