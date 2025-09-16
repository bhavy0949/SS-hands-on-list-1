/*
============================================================================
Name : q5.c
Author : Bhavy Gupta
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 7th Sep, 2025.
============================================================================
*/
#include <fcntl.h>  // Import for `creat` system call
#include <stdio.h>      // Import printf

int main(){
        int fd1 = creat("test1.txt",0644);
        int fd2 = creat("test2.txt",0644);
        int fd3 = creat("test3.txt",0644);
        int fd4 = creat("test4.txt",0644);
        int fd5 = creat("test5.txt",0644);
        printf("File Descriptors: %d %d %d %d %d", fd1, fd2, fd3, fd4, fd5);
        printf("\nAll files created and remain open.\n");
        printf("Program now running an infinite loop.\n");
        while(1);
        return 0;
}
/*
File Descriptors: 3 4 5 6 7
All files created and remain open.
Program now running an infinite loop.
*/