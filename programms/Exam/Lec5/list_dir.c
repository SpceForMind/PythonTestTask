
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <regex.h>



int isValid(char *filename)
{
	char *regexp = "^test-[[:digit:]]{4}\\.txt$";
	regex_t regeComp;

	if(regcomp(&regexComp, regexexp, REG_EXTENDED))
		return 0;


}


void WalkToDir(char *dirname)
{
	DIR *



}





int main()
{






	return 0;
}
