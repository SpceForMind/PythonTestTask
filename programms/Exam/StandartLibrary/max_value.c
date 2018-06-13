
#include <stdio.h>
#include <stdarg.h>


int FindMaxValue(int count, ...)
{
	va_list ap;
	va_start(ap, count);

	int max_num;
	int cur_num;
	max_num = va_arg(ap, int);

	for(int i = 1; i < count; ++i)
	{
		cur_num = va_arg(ap, int);
		if(max_num < cur_num)
			max_num = cur_num;
	}
	return max_num;
}



int main()
{
	printf("%d\n", FindMaxValue(6, -1, -2, -3, -4, -5, 10));




	return 0;
}
