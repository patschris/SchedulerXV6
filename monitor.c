#include "types.h"
#include "stat.h"
#include "user.h"

/*
	Calls the system call that prints all the scheduler's processes
*/
int 
main(void)
{
	printRunningProc();
	exit();
}