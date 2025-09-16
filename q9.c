/*
============================================================================
Name : q9.c
Author : Bhavy Gupta
Description : Write a program to print the following information about a given file.
              a. inode
              b. number of hard links
              c. uid
              d. gid
              e. size
              f. block size
              g. number of blocks
              h. time of last access
              i. time of last modification
              j. time of last change
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>    // For printf, perror, fprintf
#include <sys/stat.h> // For the stat struct and function
#include <time.h>     // For ctime to format time

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Command must be like: %s <filename>\n", argv[0]);
        return 1;
    }
    struct stat fileStat;
    if (stat(argv[1], &fileStat) == -1) {
        perror("Error getting file stats");
        return 1;
    }
    printf("--- File Information for: %s ---\n", argv[1]);
    printf("Inode number: \t\t%lu\n", fileStat.st_ino);
    printf("Number of hard links: \t%u\n", fileStat.st_nlink);
    printf("User ID (UID): \t\t%u\n", fileStat.st_uid);
    printf("Group ID (GID): \t\t%u\n", fileStat.st_gid);
    printf("Size: \t\t\t%ld bytes\n", fileStat.st_size);
    printf("Block size: \t\t%d bytes\n", fileStat.st_blksize);
    printf("Number of blocks: \t%lld\n", (long long)fileStat.st_blocks);
    printf("Time of last access: \t%s", ctime(&fileStat.st_atime));
    printf("Time of last modification: \t%s", ctime(&fileStat.st_mtime));
    printf("Time of last change: \t%s", ctime(&fileStat.st_ctime));
    return 0;
}
/*
--- File Information for: testfile.txt ---
Inode number:           131587
Number of hard links:   1
User ID (UID):          1000
Group ID (GID):         1000
Size:                   6 bytes
Block size:             4096 bytes
Number of blocks:       8
Time of last access:    Sun Sep  7 12:35:00 2025
Time of last modification: Sun Sep  7 12:35:00 2025
Time of last change:    Sun Sep  7 12:35:00 2025
*/