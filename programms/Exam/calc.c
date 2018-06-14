
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>







int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("No arguments from command line!");
		return 0;
	}

	char *opts = "a:b:o:"; 
	int v1;
	int v2;
	char operator; //+-/*
	int opt; //For save next key of option

	while((opt = getopt(argc, argv, opts))!= -1)
	{
		switch(opt)
		{
			case 'a':
				v1 = atoi(optarg);
				break;
			case 'b':
				v2 = atoi(optarg);
				break;
			case 'o':
				operator = optarg[0];
				break;
		}
	}
	printf("operator = %c\n", operator);

	switch(operator)
	{
		case '+':
			printf("%d + %d = %d", v1, v2, v1 + v2);
			break;
		case '-':
			printf("%d - %d = %d", v1, v2, v1 - v2);
			break;
		case 'x':
			printf("%d x %d = %d", v1, v2, v1 * v2);
			break;
		case '/':
			printf("%d / %d = %d", v1, v2, v1 / v2);
			break;
	}

	return 0;
}
