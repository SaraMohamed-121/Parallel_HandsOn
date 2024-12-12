#include <iostream>
#include <omp.h>
using namespace std;
int main() {
    int size = 10, C = 0, final_sum = 0;
    int* A = new int[size];
    int* B = new int[size];

#pragma omp parallel shared(A, B, final_sum) firstprivate(C)
    {
#pragma omp for
        for (int i = 0; i < size; i++) {
            A[i] = B[i] = i; 
        }

#pragma omp barrier // Ensure all threads finish initialization before proceeding
#pragma omp single
        cout << "Arrays are filled!!" << std::endl;

#pragma omp for
        for (int i = 0; i < size; i++) {
            C += A[i] * B[i]; 
        }

#pragma omp critical
        final_sum += C; 

#pragma omp barrier // Ensure all threads finish computation before printing the result
#pragma omp single
        cout << "Result = " << final_sum << std::endl;
    }
    return 0;
}
