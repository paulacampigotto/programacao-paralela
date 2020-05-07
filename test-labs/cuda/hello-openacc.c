#include <stdio.h>
#include "openacc.h"

int main(void)
{
	int i = 0;
	#pragma acc parallel
	  i += 1;

	printf("Hello World\n");
	return 0;
}
