/*
============================================================================
Name : q30.c
Author : Bhavy Gupta
Description :Write a program to run a script at a specific time using a Daemon process.
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <time.h>

int main() {
    
    pid_t process_id = fork();
    if (process_id < 0) {
        exit(0);
    }
    umask(0);
    setsid();
    chdir("/");
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    int target_hour = 1;
    int target_min = 10;
    
    while (1) {
       time_t now =  time(NULL);
       struct tm *t = localtime(&now);
       if (t->tm_hour == target_hour && t->tm_min == target_min) {
          system("/myscript.sh"); // Path to your script
          sleep(60);
       }
       sleep(1);
    }
}
