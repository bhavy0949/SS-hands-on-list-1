/*
============================================================================
Name : q6.c
Author : Bhavy Gupta
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 7th Sep, 2025.
============================================================================
*/
#include <unistd.h>	// Import read and write
#include <stdio.h>	// Import perror

int main(){
	char *buffer[100];
	int readByte,writeByte;
	while(1){
		readByte = read(0,buffer,1);
		writeByte = write(1,buffer,1);

		if(readByte == -1 || writeByte == -1){
			perror("Error while reading from STDIN / writing to STDOUT\n");
			return 0;
		}
	}	
	return 0;
}
/*
Bhavy
Bhavy
*/