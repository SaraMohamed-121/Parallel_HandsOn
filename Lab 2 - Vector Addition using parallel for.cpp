#include <omp.h>
#include <stdio.h>

#define N 100
int main(int argc, char* argv[])
{
	int nthreads, tid, i, chunk =10;
	float a[N], b[N], c[N];

	for (i = 0; i < N; i++)
		a[i]=b[i] = i * 1.0;

#pragma omp parallel shared(a, b, c, nthreads, chunk) private(i,tid)
	{
		tid = omp_get_thread_num();

		if (tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads %d\n", nthreads);
		}
		printf("Thread %d starting...\n", tid);

#pragma omp for schedule(dynamic, chunk)

		for (i = 0; i < N; i++)
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

	
// //#pragma omp parallel private(id,i) 
// #pragma omp parallel shared(a, b, c, nthread) private(i,id)
// 	{
// 		nthread = omp_get_num_threads();
// 		id = omp_get_thread_num();
// 		if (id == 0) {
// 			printf(" nthread %d\n", nthread);
// 		}

		
// 	#pragma omp for 
// 		//for (i = id * (N / nthread); i < (id + 1) * (N / nthread); i++) {
// 		for (i = 0; i < N; i++) {
// 			c[i] = a[i] + b[i];
// 			printf("id %d ----  i:%d,  c: %d \n",id,i, c[i]);
// 		}
// 	}
// 	return 0;
// }


