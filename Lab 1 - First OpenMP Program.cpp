#include <tchar.h>
#include <Windows.h>
#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int id, nthreads;
	omp_set_num_threads(4);
#pragma omp parallel private(id)
	{
		id = omp_get_thread_num();

		printf("Hello World from thread %d\n", id);

	}
}

