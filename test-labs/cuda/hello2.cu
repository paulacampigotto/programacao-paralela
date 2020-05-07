#include <stdio.h>

__device__ const char *STR = "HELLO WORLD!";
const char STR_LENGTH = 12;

__global__ void hello()
{
	printf("%c dimGrid(%d) dimBlock\n", STR[threadIdx.x % STR_LENGTH]);
}

int main(void)
{
	int num_threads = STR_LENGTH;
	int num_blocks = 2;
	dim3 dimBlock (16,16);
	dim3 dimGrid(32,32);
	hello<<<dimGrid,dimBlock>>>();
	cudaDeviceSynchronize();

	return 0;
}
