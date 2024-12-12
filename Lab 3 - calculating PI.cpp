#include<stdio.h>
#include <omp.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	int npoints = 10000000, i, seed;
	double rand_no_x, rand_no_y, sum=0.0,pi;

#pragma omp parallel private (rand_no_x, rand_no_y, i, seed) num_threads (8)
	{
		sum = 0.0;
#pragma omp for reduction(+: sum)
		for (i = 0; i < npoints; i++)
		{
			rand_no_x = (double)(rand() % 100) / (double)(100.0);
			rand_no_y = (double)(rand() % 100) / (double)(100.0); 
			if (((rand_no_x - 0.5) * (rand_no_x - 0.5) + (rand_no_y - 0.5)*(rand_no_y - 0.5)) <= 0.25)
				sum++;
		}
	}
	printf("PI = %lf\n", (sum / (double)npoints) * 4.0);
}