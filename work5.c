#include "types.h"
#include "user.h"
#include "fcntl.h"

#define SIZE 9000

/*
    Reference: https://stackoverflow.com/questions/32872767/how-to-create-files-in-the-xv6
    Runs for about 2 minutes 
*/

char name[SIZE];
char out[SIZE];
char out2[SIZE];

/* For each i the function finds the amount of the divisors */
void 
foo(int *sum)
{
    int i,j,iter=900;
    *sum=0;
    for(i=1;i<iter;i++){
        for(j=1;j<i;j++){
            if(i%j==0){
                *sum= *sum+j;
            }
        }
    }

}

/* Create a file called "testfile" and open it with read and write permissions */
int 
createFile()
{
    int fd = open("testfile", O_CREATE | O_RDWR);
    if (fd < 0) {
        printf(1, "Error: create test file failed\n");
        exit();
    }
    return fd;
}

/* Fill a buffer with 9000 characters and write all of them in an output file */
void 
writeToFile(int fd) 
{
    int i, size = SIZE*sizeof(char);
    for (i=0; i<SIZE; i++) {
    	name[i] = 'a' + i%5;
    }
    if(write(fd, name, size) != size){
        printf(1, "Error: write to backup file failed\n");
        exit();
    }
    close(fd);
}

/* Open a testfile, read all the characters that was written by writeToFile and close it */
void 
readFromFile(int *n) 
{
	int fd = open("testfile", O_RDONLY);
	int size = SIZE*sizeof(char);
    if(fd < 0) {
        printf(1, "Error: read testfile file failed\n");
        exit();
    }
    if (*n < 10) {
        if((*n=read(fd, &out, size)) != size){
            printf(1, "Error: read from backup file failed\n");
            exit();
        }
    }
    else {
        if((*n=read(fd, &out2, size)) != size){
            printf(1, "Error: read from backup file failed\n");
            exit();
        }
    }
    close(fd);
}

int
main(void)
{
	int i,n=0, iter = 6100, fd;
	// Creating a temporary file
	fd = createFile();
    // write once 9000 characters
	writeToFile(fd);
    // read iteratively all the file that contains 9000 characters
	for (i=0; i< iter; i++) {
		readFromFile(&n);
        foo(&n);
        if (n==-1) break;
	}
	// Destroy the file
	if(unlink("testfile") < 0){
		printf(1, "Error: unlink failed\n");
	}
    printf(1, "work5: Exiting with %c & %c\n",out[10], out2[10]);
    exit();
}