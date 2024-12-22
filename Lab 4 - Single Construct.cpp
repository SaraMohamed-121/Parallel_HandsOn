#include <stdio.h>
#include <omp.h>

int main()
{
	int id;
	omp_set_num_threads(5);

#pragma omp parallel private(id)
	{
		id = omp_get_thread_num();
		printf("Hello World from thread %d\n", id);

#pragma omp barrier	//wait all
#pragma omp single
		printf("There are %d Threads in the team!! \n", omp_get_num_threads());
	

	}
}
