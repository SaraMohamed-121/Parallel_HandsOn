#include<stdio.h>
#include <omp.h>

int main()
{
	int i, n = 100, chunk = 10;
	float a[100], b[100], result = 0.0;
	
	for (i = 0; i < n; i++)
	{
		a[i] = i * 1.0;
		b[i] = i * 2.0;
	}
#pragma omp parallel for default (shared) private(i) schedule(static, chunk) reduction(+:result)
		for (i = 0; i < n; i++)
			result = result + (a[i] * b[i]);
	printf("Final result= %f\n", result);
}

// #include<omp.h>
// #include<iostream>
// #define N 10
// using namespace std;
// int main() {

// 	omp_set_num_threads(5);
// 	int id,nthread;
// 	int a[N], b[N], c=0;
// 	int i;
// 	for (i = 0; i < N; i++) {
// 		a[i] = b[i] = 1;
// 	}

	
// //#pragma omp parallel private(id,i) 
// #pragma omp parallel shared(a, b, nthread) private(i,id) reduction (+: c)
// 	{
// 		nthread = omp_get_num_threads();
// 		id = omp_get_thread_num();
// 		if (id == 0) {
// 			printf(" nthread %d\n", nthread);
// 		}

		
// 	#pragma omp for nowait 
// 		//for (i = id * (N / nthread); i < (id + 1) * (N / nthread); i++) {
// 		for (i = 0; i < N; i++) {
// 			c += a[i] * b[i];
// 			printf("id %d ----  i:%d,  c: %d \n",id,i, c);
// 		}
// 	}
// 	printf(" c: %d \n", c);
// 	return 0;
// }

