/*
============================================================================
Name : q27.c
Author : Bhavy Gupta
Description :Write a program to execute ls -Rl by the following system calls
             a. execl
             b. execlp
             c. execle
             d. execv
             e. execvp
Date: 6th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc,char *env[])
{
    char *path = "/bin/ls";
    char *prog = "ls";
    execl(path, prog, "-Rl", NULL);//a
    execlp(path, prog, "-Rl", NULL);//b
    execle(path, prog, "-Rl" ,"27c_example/",NULL, env);//c
    char *argv[] = {path,"-Rl",NULL};
    execv(path, argv);//d
    char *buf[] = {path2, "-Rl", NULL};
    execvp(path2, buf);//e     
    return 0;
}
/*
Output:
total 308
-rwxr-xr-x 1 root root 70520 Sep  6 22:26 g12
-rw-r--r-- 1 root root    26 Sep  6 22:19 m_file.txt
drwxr-xr-x 5 root root  4096 Aug 29 00:36 problem1
drwxr-xr-x 2 root root  4096 Sep  6 21:09 problem10
drwxr-xr-x 2 root root  4096 Sep  5 15:06 problem2
drwxr-xr-x 2 root root  4096 Sep  5 22:56 problem3
drwxr-xr-x 2 root root  4096 Sep  6 10:31 problem4
drwxr-xr-x 2 root root  4096 Sep  6 11:00 problem5
drwxr-xr-x 2 root root  4096 Sep  6 15:17 problem6
drwxr-xr-x 2 root root  4096 Sep  6 16:30 problem7
drwxr-xr-x 2 root root  4096 Sep  6 17:39 problem8
drwxr-xr-x 2 root root  4096 Sep  6 18:32 problem9
-rwxr-xr-x 1 root root 70512 Sep  6 22:18 q11
-rw-r--r-- 1 root root  1125 Sep  6 22:19 q11.c
-rw-r--r-- 1 root root  1453 Sep  6 22:28 q12.c
-rwxr-xr-x 1 root root 70504 Sep  6 22:45 q13
-rw-r--r-- 1 root root  1305 Sep  6 22:47 q13.c
-rwxr-xr-x 1 root root 70544 Sep  6 23:12 q14
-rw-r--r-- 1 root root  1659 Sep  6 23:12 q14.c
-rwxr-xr-x 1 root root 70360 Sep  6 23:24 q15
-rw-r--r-- 1 root root  2571 Sep  6 23:25 q15.c
-rw-r--r-- 1 root root  3096 Sep  7 00:19 q18.c
-rwxr-xr-x 1 root root 70512 Sep  6 21:39 q19
-rw-r--r-- 1 root root  1052 Sep  6 21:40 q19.c
-rwxr-xr-x 1 root root 70496 Sep  6 21:51 q20
-rw-r--r-- 1 root root  1009 Sep  6 21:51 q20.c
-rwxr-xr-x 1 root root 70440 Sep  6 21:52 q21
-rw-r--r-- 1 root root   653 Sep  6 21:52 q21.c
-rwxr-xr-x 1 root root 70584 Sep  6 23:41 q22
-rw-r--r-- 1 root root   977 Sep  6 23:44 q22.c
-rwxr-xr-x 1 root root 70560 Sep  6 23:48 q23
-rw-r--r-- 1 root root  1279 Sep  6 23:48 q23.c
-rwxr-xr-x 1 root root 70520 Sep  7 00:10 q24
-rw-r--r-- 1 root root   999 Sep  7 00:13 q24.c
-rw-r--r-- 1 root root  1934 Sep  7 00:14 q25.c
-rwxr-xr-x 1 root root 70584 Sep  7 00:27 q27
-rw-r--r-- 1 root root   837 Sep  7 00:27 q27.c
-rwxr-xr-x 1 root root 70400 Sep  7 00:21 q27_a
*/
