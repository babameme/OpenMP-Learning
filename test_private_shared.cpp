#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
int main(){
	int var1 = 0, var3 = 0;
	#pragma omp parallel private(var1) shared(var3)
	{
		int ID = omp_get_thread_num();
		printf("Thread num %d \n", ID);
		var1++;
		var3++;
		printf("%d %d \n", var1, var3);
	}
}