#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "source/terminal.h"


int main()
{
	char red[] = "\e[101;1m";
	char yellow[] = "\e[103;1m";
	char green[] = "\e[102;1m";
	char blue[] = "\e[106;1m";

	int columns = getWindowSize() - 2;

	// int day = getDayOfYear();
	int day = 365;
	float ratio = day / 365.0;
	int offset = 4;

	char color[10];
	strcpy(color ,
	ratio == 1 ? green :
	ratio > 0.8 ? blue :
	ratio > 0.5 ? yellow :
	red);

	printf("\e[1;37m%*.d / 365, %d day%s left" , offset , day , 365 - day , day == 364 ? "" : "s");

	// printf("columns: %d\n", columns);
	// printf("day: %7d\n", day);

	printf("%*.s%d%%\e[m\n" , columns / 2 - offset - 16 , "" , (int)(ratio * 100));
	printf(" %s%*.s\e[m%*.s \n" , color  , (int)ceil(ratio * columns) , "" , (int)floor((1 - ratio) * columns) , "");

	return 0;  // make sure your main returns int
}
