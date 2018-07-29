#include "types.h"
#include "stat.h"
#include "user.h"

/* For each i the function finds the amount of the divisors (runs for about 2 minutes) */
void 
foo(int *sum)
{
	int i,j,iter=66000;
	*sum=0;
	for(i=1;i<iter;i++){
		for(j=1;j<i;j++){
			if(i%j==0)
				*sum= *sum+j;
		}
	}
}

int 
main(void)
{
	int sum=0;
	foo(&sum);
	/* Print the sum, otherwise it will be removed from the compiler as unused */
	printf(1,"work1: Ending with sum: %d\n",sum);
	exit();
}