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
        printf(1, "error: write to backup file failed\n");
        exit();
    }
    close(fd);
}

/* Open a testfile, read all the characters that was written by writeToFile and close it */
void 
readFromFile() 
{
	int fd = open("testfile", O_RDONLY);
	int size = SIZE*sizeof(char);
    if(fd < 0) {
        printf(1, "Error: read testfile file failed\n");
        exit();
    }
    if(read(fd, &out, size) != size){
        printf(1, "Error: read from backup file failed\n");
        exit();
    }
    close(fd);
}

int
main(void)
{
	int i, iter = 31000, fd;
	// Creating a temporary file
	fd = createFile();
    // write once 9000 characters
	writeToFile(fd);
    // read iteratively all the file that contains 9000 characters
	for (i=0; i< iter; i++) {
		readFromFile();
	}
	// Destroy the file
	if(unlink("testfile") < 0){
		printf(1, "Error: unlink failed\n");
	}
    printf(1, "work3: exiting\n");
    exit();
}