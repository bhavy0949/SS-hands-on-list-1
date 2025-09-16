/*
============================================================================
Name : q21.c
Author : Bhavy Gupta
Description :  Write a program, call fork and print the parent and child process id.
Date: 6th Sep, 2025.
============================================================================
*/

#include <sys/types.h> // Import for `fork` & `getpid` system call
#include <unistd.h>    // Import for `fork` & `getpid` system call
#include <stdio.h>     // Import for printf function

int main(){
	if(!fork()){
		printf("Child PID: %d\n",getpid());
		printf("Parent PID: %d\n",getppid());
	}
	return 0;
}

/*
./a.out
Child PID: 431
Parent PID: 1
*/
