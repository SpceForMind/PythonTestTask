
#include <stdio.h>

int CheckToDeg(unsigned long n)
{
	unsigned long deg_2 = 1;

	for(int i = 0; i < 8 * sizeof(n); ++i)
	{
		if(n == deg_2 - 1)
		       return 1;
		deg_2 <<= 1;
	}	
	return 0;
}



int main()
{
	unsigned long n;

	if(scanf("%lu", &n)!= 1)
		return 0;

	if(CheckToDeg(n))
		printf("yes");
	else
		printf("no");



	return 0;
}
