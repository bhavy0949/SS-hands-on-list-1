/*
============================================================================
Name : q4.c
Author : Bhavy Gupta
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    const char* filename = "existing_file.txt";
    printf("Step 1: Creating a dummy file named '%s'...\n", filename);
    fd = open(filename, O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        perror("Failed creating the file");
        return 1;
    }
    printf("File created successfully. Closing it for now.\n");
    close(fd);
    printf("\n\n");

    printf("Step 2: Trying to open '%s' in Read-Write mode (O_RDWR).\n", filename);
    fd = open(filename, O_RDWR);

    if (fd == -1) {
        perror("Failed to open the file in O_RDWR mode");
    } else {
        printf("Success! File opened in Read-Write mode.\n");
        printf("File Descriptor: %d\n", fd);
        close(fd);
    }
    printf("\n\n");
    
    printf("Step 3: Trying to create '%s' again, but with O_CREAT and O_EXCL flags.\n", filename);
    fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0644);

    if (fd == -1) {
        printf("open() call failed, file already exists.\n");
        
        perror("Error");
    } else {
        printf("The O_EXCL flag should have prevented this.\n");
        close(fd);
    }
    printf("\n\n");
    return 0;
}

/*
Step 1: Creating a dummy file named 'existing_file.txt'...
File created successfully. Closing it for now.


Step 2: Trying to open 'existing_file.txt' in Read-Write mode (O_RDWR).
Success! File opened in Read-Write mode.
File Descriptor: 3


Step 3: Trying to create 'existing_file.txt' again, but with O_CREAT and O_EXCL flags.
open() call failed, file already exists.
Error: File exists
*/