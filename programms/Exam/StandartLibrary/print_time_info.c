
#include <stdio.h>
#include <time.h>



void PrintTimeInfo(time_t time)
{
	const char *month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	struct tm *time_info;
	time_info = localtime(&time);
	printf("%d %s %d", time_info->tm_hour, month[time_info->tm_mon], time_info->tm_year + 1900);
}



int main()
{
	PrintTimeInfo(time(NULL));


	return 0;
}
