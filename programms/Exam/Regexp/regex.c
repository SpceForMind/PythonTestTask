
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <regex.h>

int IsValid(char *file_name)
{
	FILE *file = fopen("f2.txt", "r");
	if(!file)
		return 0;
	char buf[100];
	fgets(buf, 100, file);
	*strstr(buf, "\n") = 0;
	printf("%s\n", buf);

//	char *regexp = "^[0-9/]{1,4}\\/[0-9/]{1,2}\\/[0-9/]{1,2}[[:space:]][0-9]{1,2}\\:[0-9]{1,2}$";
	char *regexp = "^[0-9][.,]([0-9]{3}[.,])([0-9]{3}[.,])";
	regex_t regex_comp;
	if(regcomp(&regex_comp, regexp, REG_EXTENDED))
		return 0;
	
	fclose(file);
	return !regexec(&regex_comp, buf, 0, NULL, 0); 
}




int main()
{
	printf("%d", IsValid("f1.txt"));	



	return 0;
}
