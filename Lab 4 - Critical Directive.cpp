#include <stdio.h>
#include <omp.h>
#define N 10000 

int main()
{
    int i;
    long long w, a[N], sum = 0; // Use long long to avoid overflow

    // Initialize the array
    for (i = 0; i < N; i++) {
        a[i] = i + 1;
    }

    // Parallel for loop with critical directive for updating sum
#pragma omp parallel for private(w) schedule(static, 1)
    for (i = 0; i < N; i++)
    {
        w = (long long)i * i;  // Use long long to handle large values
        long long temp = w * a[i];  // Compute the contribution for this iteration
#pragma omp critical
        {
            sum += temp;  // Safely update the shared sum
        }
    }

    printf("The global sum throughout the team is %lld \n", sum);
    return 0;
}

// #include<omp.h>
// #include<iostream>
// #define N 10000 

// int main()
// {
//     int i;
//     long long w, a[N], sum = 0; // Use long long to avoid overflow

//     for (i = 0; i < N; i++) {
//         a[i] = i + 1;
//     }

// #pragma omp parallel for private(w) schedule(static, 1)
//     for (i = 0; i < N; i++)
//     {
//         w = (long long) i*i;  
//         long long temp = w * a[i]; 
// #pragma omp critical
//         {
//             sum += temp;  
//         }
//     }

//     printf("The global sum throughout the team is %lld \n", sum);
// 	return 0;
// }


