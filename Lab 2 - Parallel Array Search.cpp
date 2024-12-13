#include<stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define N 1000
int main()
{
	int arr[N];
	int id;
	srand(time(NULL));
	for (int i = 0; i < N; i++) 
	{
		arr[i] = (rand()%100) + 1; 
	}
	//printf("arr %d value is %d\n", i,arr[i]);
	int i;

#pragma omp parallel private(id, i)
	{
		id = omp_get_thread_num();
#pragma omp for schedule (dynamic, 50)
			for (i = 0; i < N; i++)
				if (arr[i] == 94)
					printf("found in arr [%d] by thread %d\n", i, id);
		
	}
}

// #include<omp.h>
// #include<iostream>
// #include<stdlib.h>
// #include<time.h>
// #define N 10
// using namespace std;
// int main() {
// 	int a[N];
// 	srand(time(NULL));
// 	int i;
// 	for (i = 0; i < N; i++) {
// 		a[i] = rand() % 100 + 1; ;
// 		printf("a[%d]  = %d \n", i, a[i]);
// 	}

// #pragma omp parallel 
// 	{
// #pragma omp for
// 		for (i = 0; i < N; i++) {
// 			if (a[i] == 99) {
// 				printf("a[i] == 99 \n");
// 			}
// 		}
// 	}
// 	return 0;
// }

