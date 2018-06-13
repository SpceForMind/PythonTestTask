
#include <stdio.h>
#include <string.h>


void PrintFirstIndex(char *str, char *sub_str)
{
	if(str == NULL || sub_str == NULL)
		return;
	if(strlen(str) < strlen(sub_str))
		return;
	
	char *first_index = strstr(str, sub_str);
	if(first_index == NULL)
	{
		printf("yes\n");
		printf("%d", -1);
	}
	else
		printf("%ld", first_index - &str[0]);
}



int main()
{
	char str[100];
	char sub_str[100];

	fgets(str, 100, stdin);
	fgets(sub_str, 100, stdin);
	*strstr(str, "\n") = '\0';
	*strstr(sub_str, "\n") = '\0';
	PrintFirstIndex(str, sub_str);


	return 0;
}
