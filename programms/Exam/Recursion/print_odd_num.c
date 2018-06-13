
#include <stdio.h>


void PrintOddNum()
{
	int n;
	scanf("%d", &n);
	if(n == 0)
		return;
	else if(n % 2 == 1)
	{
		printf("%d ", n);
		PrintOddNum();
	}
	else
		PrintOddNum();

}



int main()
{
	PrintOddNum();



	return 0;
}
