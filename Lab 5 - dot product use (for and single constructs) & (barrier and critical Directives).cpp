#include <iostream>
#include <omp.h>
#define N 10
using namespace std;
int main() {
    int  C = 0, final_sum = 0, A[10], B[10];

#pragma omp parallel shared(A, B, final_sum) firstprivate(C)
    {
#pragma omp for
        for (int i = 0; i < N; i++) {
            A[i] = B[i] = i;
        }

#pragma omp barrier 
#pragma omp single
        cout << "Arrays are filled!!" << endl;

#pragma omp for
        for (int i = 0; i < N; i++) {
            C += A[i] * B[i];
        }

#pragma omp critical
        final_sum += C;

#pragma omp barrier 
#pragma omp single
        cout << "Result = " << final_sum << endl;
    }
    return 0;
}
