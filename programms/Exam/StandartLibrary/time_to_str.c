
#include <stdio.h>
#include <time.h>




int main()
{
	time_t cur_time;
	printf("time: %ld\n", time(&cur_time));
	printf("cur_time = %ld\n", cur_time);
	printf("%s", ctime(&cur_time));


	return 0;
}
