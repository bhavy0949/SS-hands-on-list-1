/*
============================================================================
Name : q3.c
Author : Bhavy Gupta
Description : Write a program to create a file and print the file descriptor value. Use creat() system call
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>    
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* filename = "file_descriptor.txt";
    int file_descriptor = creat(filename, 0);

    if (file_descriptor == -1) {
        perror("Error creating file");
        return 1;
    }
    const char* text_to_write = "Hello, World!\n";
    long int bytes_written = write(file_descriptor, text_to_write, strlen(text_to_write));

    if (bytes_written == -1) {
        perror("Error writing to file");
        return 1;
    }

    printf("File '%s' created!!\n", filename);
    printf("%ld bytes were written to '%s'.\n\n", bytes_written, filename);
    printf("File descriptor value: %d\n", file_descriptor);

    close(file_descriptor);

    return 0;
}
/*
File 'file_descriptor.txt' created!!
14 bytes were written to 'file_descriptor.txt'.
File descriptor value: 3
*/