/*
============================================================================
Name        : q13.c
Author      : Bhavy Gupta
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date        : 6th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set read_fds;
    struct timeval timeout;
    int result;

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");

    result = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select error");
        return 1;
    }
    else if (result == 0) {
        printf("No data received within 10 seconds. Timeout occurred.\n");
    }
    else {
        printf("Data is available to be read from STDIN.\n");
    }

    return 0;
}


/*
Output: 
root@ubuntu-dev:~/hands_on_list1# ./q13
Waiting for input on STDIN for 10 seconds...
No data received within 10 seconds. Timeout occurred.
root@ubuntu-dev:~/hands_on_list1# ./q13
Waiting for input on STDIN for 10 seconds...
hello
Data is available to be read from STDIN.

*/
