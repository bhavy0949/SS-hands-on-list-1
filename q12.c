/*
============================================================================
Name        : q12.c
Author      : Bhavy Gupta
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date        : 6th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    int fd = open(filename, O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file flags with fcntl");
        close(fd);
        return 1;
    }
    int accessMode = flags & O_ACCMODE;
    switch (accessMode) {
        case O_RDONLY:
            printf("The file was opened in Read-Only mode.\n");
            break;
        case O_WRONLY:
            printf("The file was opened in Write-Only mode.\n");
            break;
        case O_RDWR:
            printf("The file was opened in Read-Write mode.\n");
            break;
        default:
            printf("Unknown access mode.\n");
            break;
    }
    
    close(fd);
    return 0;
}

/*
Output: 
root@ubuntu-dev:~/hands_on_list1# ./g12 m_file.txt
The file was opened in Read-Write mode.
*/
