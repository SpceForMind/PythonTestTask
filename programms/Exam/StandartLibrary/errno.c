
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>






int main()
{
	FILE *file = fopen("A.txt", "r");

	if(file)
		fclose(file);
	else
	{
		printf("errno: %d\n", errno);
		perror("fopen() ");
	}

	return 0;
}	
