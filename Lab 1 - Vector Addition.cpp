#include <omp.h>
#include <stdio.h>

#define N 100
int main(int argc, char* argv[])
{
	int nthreads, tid, i;
	float a[N], b[N], c[N];
	for (i = 0; i < N; i++)
		a[i] = b[i] = i * 1.0;

#pragma omp parallel private(i,tid)
	{
		nthreads = omp_get_num_threads();
		tid = omp_get_thread_num();

		if (tid == 0)
			printf("Number of threads = %d\n", nthreads);

		printf("Thread %d starting...\n", tid);
		for (i = tid * (N / nthreads); i < (tid + 1) * (N / nthreads); i++)
		{
			c[i] = a[i] + b[i];
			printf("Thread %d: c[%d]= %f\n", tid, i, c[i]);
		}

	}
}


// #include<omp.h>
// #include<iostream>
// #define N 10
// using namespace std;
// int main() {

// 	omp_set_num_threads(5);
// 	int id,nthread;
// 	int a[N], b[N], c[N];
// 	int i;
// 	for (i = 0; i < N; i++) {
// 		a[i] = b[i] = 1;
// 	}

	
// #pragma omp parallel private(id,i) 
// 	{
// 		nthread = omp_get_num_threads();
// 		id = omp_get_thread_num();
// 		if (id == 0) {
// 			printf(" nthread %d\n", nthread);
// 		}
// 		for (i = id * (N / nthread); i < (id + 1) * (N / nthread); i++) {
// 			c[i] = a[i] + b[i];
// 			printf("id %d ----  i:%d,  c: %d \n",id,i, c[i]);
// 		}
// 	}
// 	return 0;
// }
