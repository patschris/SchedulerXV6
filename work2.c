#include "types.h"
#include "stat.h"
#include "user.h"

/* Opens iteratively the xv6 README and read one-by-one every character (runs for about 2 minutes) */
int 
main(void)
{
	char buf[1];
	int fd, n, i, iter = 300;

    for (i=0; i<iter; i++) {
    	if((fd = open("./README", 0)) < 0){
		  printf(2, "Cannot open README\n");
		  exit();
		}
		for (;;) {
			n = read(fd, buf, sizeof(buf));
			if (n==0) break;
			if(n < 0){
				printf(2, "Read error\n");
				exit();
			}
		}
		close(fd);
    }
    printf(1,"work2: Exiting\n");
	exit();
}