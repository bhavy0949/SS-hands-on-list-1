/*
============================================================================
Name : Q10.c
Author : Bhavy Gupta
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 6th September, 2025.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argv, char *argc[])
{
	int fd = open(argc[1], O_RDWR , 0777);
        
	const char *data1 = "0123456789";
    const char *data2 = "ABCDEFGHIJ";
    
	write(fd, data1, 10);
	int move_ptr = lseek(fd, 10, SEEK_CUR);
	printf("New Offset: %d\n", move_ptr);
	write(fd, data2, 10);
	move_ptr = lseek(fd, 0, SEEK_CUR);
	printf("Offset after second write: %d\n", move_ptr);
	
	close(fd);
	printf("Run 'od -c <filename>' to inspect the contents.");
	return 0;
}
/*
Output:
root@ubuntu-dev:~/hands_on_list1/problem10# touch test.txt
root@ubuntu-dev:~/hands_on_list1/problem10# gcc q10.c -o q10_compiled
root@ubuntu-dev:~/hands_on_list1/problem10# ./q10_compiled test.txt
New Offset: 20
Offset after second write: 30
Run 'od -c <filename>' to inspect the contents.root@ubuntu-dev:~/hands_on_list1/problem10# od -c test.txt
0000000   0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
0000036
*/
