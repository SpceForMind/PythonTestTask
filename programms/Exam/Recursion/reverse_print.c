
#include <stdio.h>
#include <stdlib.h>


void ReversePrint(int *arr, int n)
{
	if(n > 1)
	{
		printf("%d ", arr[n - 1]);
		ReversePrint(arr, n - 1);
	}
	else if(n == 1)
		printf("%d", arr[n - 1]);
}




int main()
{
	int count;
	scanf("%d", &count);
	int *arr = (int *)malloc(count * sizeof(int));

	for(int i = 0; i < count; ++i)
		if(scanf("%d", &arr[i])!= 1)
			break;
	ReversePrint(arr, count);

	return 0;
}
