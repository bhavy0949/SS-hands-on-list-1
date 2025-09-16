/*
============================================================================
Name : q24.c
Author : Bhavy Gupta
Description : Write a program to create an orphan process
Date: 6th Sep, 2025.
============================================================================
*/

#include <sys/types.h> // Import for `fork` system call
#include <unistd.h>    // Import for `fork` system call
#include <stdio.h>     // Import for `printf` function

int main(){
	if(fork()){
		printf("Parent PID: %d\n", getpid());
        printf("Parent shifting to 4sec sleep\n");
        sleep(4);
		printf("Parent wakes up\n");
        printf("Exiting parent!\n");
		_exit(0);
	}else{
		printf("Child PID: %d\n", getpid());
        printf("Child shifting to 10sec sleep\n");
        sleep(10);
        printf("Child awake\n");
	}
	return 0;
}

/*
Parent PID: 577
Parent shifting to 4sec sleep
Child PID: 578
Child shifting to 10sec sleep
Parent wakes up
Exiting parent!
root@ubuntu-dev:~/hands_on_list1# Child awake
*/

