#include <stdio.h>
#include <omp.h>

int main() 
{
	int id, nthreads;
	omp_set_num_threads(5);

#pragma omp parallel private(id)
	{
		id = omp_get_thread_num();
		printf("Hello World from thread %d\n", id);

#pragma omp single
		nthreads = omp_get_num_threads();
		printf("There are %d Threads in the team!! \n", nthreads);
		

	}
}
