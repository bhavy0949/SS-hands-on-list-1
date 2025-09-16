/*
============================================================================
Name : q1_a
Author : Bhavy Gupta
Description :Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 7th Sep, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main() {
	if (symlink("original.txt", "soft_link_symlink.txt")==-1) {
		printf("symlink failed\n");
		return -1;
	}
	printf("Success\n");
	return 0;
}
/*
1. Create a target file to link to:
   $ echo "This is the original file." > original.txt

2. Compile the C code:
   $ gcc q1_a.c -o q1_a

3. Run the executable:
   $ ./q1_a

4. Verify with 'ls -l':
   $ ls -l
   total 12
   -rwxr-xr-x 1 user user 8384 Sep  7 12:00 q1_a
   -rw-r--r-- 1 user user   26 Sep  7 12:00 original.txt
   lrwxrwxrwx 1 user user   12 Sep  7 12:00 soft_link_symlink.txt -> original.txt

--- Console Output of the Program ---
Soft link created successfully.
*/
