# Scheduler xv6
## Xv6
Xv6 is a teaching OS that developed by people in MIT. It is a reimplementation of Unix v6, implemented for a modern x86−based multiprocessor using ANSI C, in order to give a good idea on how the operating system works. The source files of xv6 is provided as a printed booklet with line numbers in [\[1\]](https://pdos.csail.mit.edu/6.828/2017/xv6/xv6-rev10.pdf). To take an idea on which are the main concepts of operating systems by studying the kernel are explained, see [\[2\]](https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf). Understanding xv6 is a good start toward understanding modern operating systems. To install xv6 OS download the code from github, see [\[3\]](https://github.com/mit-pdos/xv6-public). Then, run the makefile. To run xv6, we need an emulator, called QEMU (see [\[4\]](https://www.qemu.org/index.html)). You can install the emulator with the following terminal command: `sudo apt-get install qemu`. After the installation, run `make qemu-nox`. Now, we are ready to use xv6 OS.

## Min-heap scheduler
A [heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C (see [\[5\]](https://en.wikipedia.org/wiki/Heap_(data_structure))). Our goal is to construct a min-heap scheduler to replace xv6's scheduler. This structure will be used as a priority queue for the timescheduling of the system's processes. That is, every heap's node will represent a process in READY state and its current priority. When the OS wants to pick a process to run (state: READY→RUNNING), the process with the lowest priority will be chosen (min-heap's root). The min-heap will have no more than 64 nodes. The priority of a process will be calculated as follows: \
![priorityFormulaImage](https://github.com/patschris/SchedulerXV6/blob/master/priorityFormula.png) \
where *runningTime*: total time that the process ran and used the cpu and *currentTime - creationTime*: total time that a process exists in the system after the time that it was created. \
When a process finishes a time-slice, but it's not done, we reinsert the process into the heap (READY state) with a new priority calculated by the above-mentioned formula. \
The construction of the min-heap node is based on [\[6\]](http://robin-thomas.github.io/min-heap/)

## System call printRunningProc
This system call prints all the information about the alive processes (READY, RUNNING, BLOCKED). The information that will be printed is:
* Process ID
* Process Name
* Parent process ID
* State
* Running time
* Process scheduled times


## Workloads
We made 5 small executable programs in order to test our scheduler: 
1. The fist program does multiple computations iteratively.
2. The second program does short and iterative I/Os. Specifically, read and write character by character.
3. The thrird program is similar to the second, but it reads a few thousand characters per I/O.
4. The fourth program is similar to the second, but it does multiple computations between the I/Os.
5. The fifth program is similar to the fourth, but it reads a few thousand characters per I/O.

## Makefile
We had to make some changes in order to include the newly created files.

## Files
In this repository, you can see only the files that I have changed in xv6 implementation and the newly created files. To test the scheduler you have to download the [xv6 source code](https://github.com/mit-pdos/xv6-public) and move this code inside the xv6 folder.

## References
[1] https://pdos.csail.mit.edu/6.828/2017/xv6/xv6-rev10.pdf \
[2] https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf \
[3] https://github.com/mit-pdos/xv6-public \
[4] https://www.qemu.org/index.html \
[5] https://en.wikipedia.org/wiki/Heap_(data_structure) \
[6] http://robin-thomas.github.io/min-heap/
