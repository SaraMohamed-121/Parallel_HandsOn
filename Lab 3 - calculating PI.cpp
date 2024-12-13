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


// #include<omp.h>
// #include<iostream>
// #include<time.h>
// #include<stdlib.h>
// #define N 1000000
// using namespace std;
// int main() {
// 	omp_set_num_threads(8);
// 	srand(time(NULL));
// 	double x_point, y_poiny, Ninner = 0;
// 	int i;
	
// #pragma omp parallel private(i) reduction(+:Ninner)
// 	{
// 		#pragma omp for
// 		for (int i = 0; i < N; i++)
// 		{
// 			x_point = (double)(rand() + 1) / RAND_MAX;//0 to 1
// 			y_poiny = (double)(rand() + 1) / RAND_MAX;
// 			if (((x_point - 0.5) * (x_point - 0.5)) + ((y_poiny - 0.5) * (y_poiny - 0.5)) <= 0.25) {
// 				Ninner++;
// 			}
// 		}

// 	}
// 	//printf("Ninner %f \n", Ninner);
// 	printf("pi %f \n", (Ninner / N) * 4.0);
// 	return 0;
// }

