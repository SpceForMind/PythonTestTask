
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <getopt.h>

typedef struct
{	
	int final;
	int reverse; 
	int verbose;
} Config;



void PrintHelp()
{
	printf("getopt example\n");
	printf("-f <value> - final value\n");
	printf("r - reverse\n");
	printf("-v - verbose\n");
	printf("-h - ? - help\n");
}


int main(int argc, char **argv)
{
	Config config = {0, 0, 0};
	char *opts = "f:rvh?"; //short keys
	struct option long_opts[] = {
		{"verbose", no_argument, NULL, 'v'},
		{"reverse", no_argument, NULL, 'r'},
	       	{"lognlong", 0, NULL, 0},	
		{NULL, 0, NULL, 0}};
	int opt;
	int long_index;
	opt = getopt_long(argc, argv, opts, long_opts, &long_index);

	while(opt!= -1)
	{
		switch(opt)
		{
			case 'f':
				config.final = atoi(optarg);
				break;
			case 'r':
				config.reverse = 1;
				break;
			case 'v':
				config.verbose = 1;
				break;
			case 'h':
			case '?':
				PrintHelp();
				return 0;
			case 0:
				printf("->%s\n", long_opts[long_index].name);
		}

		opt = getopt_long(argc, argv, opts, long_opts, &long_index);
	}
	printf("final = %d\n", config.final);
	printf("reverse = %d\n", config.reverse);
	printf("verbose = %d\n", config.verbose);


	for(int i = 0; i < argc; ++i)
		printf("%s\n", argv[i]);

	return 0;
}
