
#include <stdio.h>
#include <string.h>
#include <math.h>


char *FindSubstr(char *str, char *substr)
{
	char *index = str;
	for(int i = 0; i < strlen(str) - strlen(substr) + 1; ++i)
		for(int j = 0; j < strlen(substr); ++j)
			if(str[i + j] != substr[j])
			{
				++index;
				break;
			}
			else if(j == strlen(substr) - 1)
				return index;
	return NULL;
}


int main()
{
	char *index = FindSubstr("12345", "5");
	if(index)
		printf("%s", index);


	return 0;
}
