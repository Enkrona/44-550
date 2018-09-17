#include <stdio.h>

int main()
{

	//  We must always make sure to do "fclose" due to the buffer on SSDs being too fast.
	//  It wouldn't finish writing to the disk in time, causing crashes

	//  FILE * is a pointer for file handler
	FILE * pFile;
	int n;
	char name [100];

	pFile = fopen("myfile.txt", "w");
	
	// Some magic goes in here writing to the file
	
	flose(pFile);	

	return 0;
}
