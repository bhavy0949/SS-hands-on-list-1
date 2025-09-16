/*
============================================================================
Name : q21.c
Author : Bhavy Gupta
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the
               descriptors and check whether the file is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl
Date: 6th Sep, 2025.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("m_file.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    // dup
    int d_fd = dup(fd);
    write(fd, "OG_1\n", 5);
    write(d_fd, "DUP_1\n", 6);

    // dup2
    int d2_fd = dup2(fd, 99);
    write(d2_fd, "DUP2_2\n", 7);

    // fcntl
    int f_fd = fcntl(fd, F_DUPFD, 0);
    write(f_fd, "FCNTL_3\n", 8);

    close(fd);
    close(d_fd);
    close(d2_fd);
    close(f_fd);
    
    return 0;
}

/*
--- Output ---
This program does not print anything to the console.
It creates a file named "m_file.txt".

Contents of m_file.txt:
OG_1
DUP_1
DUP2_2
FCNTL_3
*/
