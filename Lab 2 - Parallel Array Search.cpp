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