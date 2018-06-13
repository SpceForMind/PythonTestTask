
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100


int Compare(const void *v1, const void *v2)
{
	if(*((int *)v1) > *((int *)v2))
		return 1;
	if(*((int *)v1) == *((int *)v2))
		return 0;
	else
		return -1;
}



int main()
{
	int arr[MAXSIZE];

	for(int i = 0; i < MAXSIZE; ++i)
		if(scanf("%d", &arr[i])!= 1)
			break;
	
	int key = 0;
	int *null_index = (int *)bsearch(&key, arr, MAXSIZE, sizeof(int), Compare);
	printf("%ld", (null_index - arr) + 1);

	return 0;
}
