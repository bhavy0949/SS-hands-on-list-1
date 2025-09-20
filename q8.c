/*
============================================================================
Name : q8.c
Author : Bhavy Gupta
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date: 7th Sep, 2025.
============================================================================
*/
#include <fcntl.h>   // For open() and O_RDONLY
#include <unistd.h>  // For read(), write(), close()
#include <stdio.h>   // For perror, printf

int main(int argc, char *argv[]) {
    
    int source_fd = open("source.txt", O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char line_buffer[1024];
    char single_char_buffer[1];
    ssize_t readByte;
    int line_index = 0;

    while ((readByte = read(source_fd, single_char_buffer, 1)) > 0) {
        if (line_index < 1024 - 1) {
            line_buffer[line_index] = single_char_buffer[0];
            line_index++;
        }
        if (single_char_buffer[0] == '\n') {
            write(1, line_buffer, line_index);
            sleep(1);
	    line_index = 0; 
        }
    }
    
    if (line_index > 0) {
        write(1, line_buffer, line_index);
    }

    close(source_fd);
    return 0;
}
/*
text file
line2
line3
 */
