#include <cuda.h>

#include <stdlib.h>
#include <stdio.h>

#include "cuPrintf.cu"
#include "Function.cuh"

__global__ void testKernel()
{
	size_t size = 123;
	char* ptr = (char*)malloc(size);
	memset(ptr, 0, size);
	printf("Thread %d got pointer: %p\n", threadIdx.x, ptr);
	free(ptr);
}

__host__ void init()
{
	//cudaPrintfInit();

	testKernel<<<10, 64>>>();

	{
		cudaError_t cudaerr = cudaDeviceSynchronize();
		if (cudaerr != CUDA_SUCCESS)
			printf("kernel launch failed with error \"%s\".\n",
			cudaGetErrorString(cudaerr));
		else
			printf("success.\n");
	}

	cudaDeviceSynchronize();

	//cudaDeviceSynchronize();
	//cudaPrintfDisplay(stdout, true);
	//cudaPrintfEnd();
}