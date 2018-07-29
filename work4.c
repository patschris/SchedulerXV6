#include "types.h"
#include "stat.h"
#include "user.h"

/* For each i the function finds the amount of the divisors (runs for about 2,5 minutes) */
void 
foo(int *sum)
{
	int i,j,iter=500;
	*sum=0;
	for(i=1;i<iter;i++){
		for(j=1;j<i;j++){
			if(i%j==0){
				*sum= *sum+j;
			}
		}
	}

}


int 
main(void)
{
	int i, fd, n=0, iter = 10, limit=10;
	char buf[1], otherbuf[1];
	/*
	 *	Opens iteratively the xv6 README and read one-by-one every character
	 *	After every read, call foo to do some calculations
	 *	Based on the calculations, write the output in different buffers
	*/
    for (i=0; i<iter; i++) {
		if((fd = open("./README", 0)) < 0){
		  printf(1, "Cannot open README\n");
		  exit();
		}
		for (;;) {
		    if (n<limit) n = read(fd, buf, sizeof(buf));
			else n = read(fd, otherbuf, sizeof(otherbuf));
			if (n==0) {
				foo(&n);
				break;
			}
			if(n < 0){
				printf(1, "Read error\n");
				exit();
			}
			foo(&n);

		}
		close(fd);
    }
    printf(1,"work4: Exiting with %d, %s & %s\n", n, buf, otherbuf);
	exit();
}