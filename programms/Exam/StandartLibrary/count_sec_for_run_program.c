
#include <stdio.h>
#include <time.h>




int main()
{

	int count_clock = clock();
	printf("count_clock = %d\n", count_clock);
	printf("Count sec with start of programm = %f\n", ((float)count_clock) / CLOCKS_PER_SEC); 

	return 0;
}
