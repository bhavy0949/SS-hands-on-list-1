/*
============================================================================
Name : q7.c
Author : Bhavy Gupta
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src_fd, dst_fd;
    char buffer[1024];
    ssize_t bytes_read;

    src_fd = open("source.txt", O_RDONLY);
    if (src_fd == -1) {
        printf("Error: Could not open source file.\n");
        return 1;
    }

    dst_fd = open("destination.txt", O_CREAT | O_WRONLY, 0644);
    if (dst_fd == -1) {
        printf("Error: Could not create destination file.\n");
        close(src_fd);
        return 1;
    }

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dst_fd, buffer, bytes_read);
    }
    
    close(src_fd);
    close(dst_fd);
    printf("File copied successfully!\n");
    return 0;
}
/*
File copied successfully!
*/