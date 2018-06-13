
#include <stdio.h>



int Fact(int num)
{
	if(num == 1 || num == 0)
		return 1;
	return num * Fact(num - 1);
}



int main()
{
	printf("Fact(0) = %d\n", Fact(0));	



	return 0;
}
