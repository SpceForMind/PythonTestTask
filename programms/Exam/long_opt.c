
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>





int main(int argc, char *argv[])
{
	char *opts = "a:b:o:";
	const struct option long_option[] = {
		{"value1", 1, NULL, 'a'},
		{"value2", 1, NULL, 'b'},
		{"operation", 1, NULL, 'o'},
		{0, 0, 0, 0}};
	int opt;
	int opt_ind;

	opt = getopt_long(argc, argv, opts, long_option, &opt_ind);
	
	int v1, v2;
	char operation;

	while(opt!= -1)
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
				operation = optarg[0];
		}
		opt = getopt_long(argc, argv, opts, long_option, &opt_ind);
	}

	switch(operation)
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
