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