#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
int main(){
	int tid, a[11];
	omp_set_num_threads(4);
	for (int i = 0; i < 11; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("Thread %d \n", tid);
		for (int i = 0; i < 11; i++){
			if (i % 4 == tid){
				a[i] = tid;
				printf("Fix element %d %d \n", i, a[i]);
			}
		}
	}
	for (int i = 0; i < 11; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}