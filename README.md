# Scheduler xv6
## Xv6
Xv6 is a teaching OS that developed by people in MIT. It is a reimplementation of Unix v6, implemented for a modern x86−based 
multiprocessor using ANSI C, in order to give a good idea on how the operating system works. The source files of xv6 is provided
as a printed booklet with line numbers in [\[1\]](https://pdos.csail.mit.edu/6.828/2017/xv6/xv6-rev10.pdf). To take an idea on 
which are the main concepts of operating systems by studying the kernel are explained, see 
[\[2\]](https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf). Understanding xv6 is a good start toward understanding modern
operating systems. To install xv6 OS download the code from github, see [\[3\]](https://github.com/mit-pdos/xv6-public). Then, 
run the makefile. To run xv6, we need an emulator, called QEMU (see [\[4\]](https://www.qemu.org/index.html)). You can install 
the emulator with the following terminal command: `sudo apt-get install qemu`. After the installation, run `make qemu-nox`. Now,
we are ready to use xv6 OS.

## Min-heap scheduler

## System call printRunningProc
This system call prints all the information about the processes in the min heap scheduler.

## Workloads
We made 5 small executable programs to test our scheduler: 
1. The fist program does multiple computations iteratively.
2. The second program does short and iterative I/Os. Specifically, read and write character by character.
3. The thrird program is similar to the second, but it reads a few thousand characters per I/O.
4. The fourth program is similar to the second, but it does multiple computations between the I/Os.
5. The fifth program is similat to the fourth, but it reads a few thousand characters per I/O.

## Makefile

## References
[1] https://pdos.csail.mit.edu/6.828/2017/xv6/xv6-rev10.pdf \
[2] https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf \
[3] https://github.com/mit-pdos/xv6-public \
[4] https://www.qemu.org/index.html \
[5] http://robin-thomas.github.io/min-heap/
