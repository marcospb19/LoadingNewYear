#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "source/terminal.h"


int main()
{
	char red[] = "\e[101;1m";
	char yellow[] = "\e[103;1m";
	char blue[] = "\e[106;1m";
	char green[] = "\e[102;1m";
	char magenta[] = "\e[105;1m";

	int columns = getWindowSize() - 2;

	int day = getDayOfYear();

	float ratio = day / 365.0;
	int offset = 4;

	char color[10];
	strcpy(color ,
	ratio == 1 ? green : // Yeah, fireworks!
	ratio > 0.8 ? blue : // Smeels like the end is nearby...
	ratio > 0.5 ? yellow : // Half gone, better than nothing
	day <= 10 ? magenta : // First 10 days after that party
	red); // Nothing to celebrate

	printf("\e[1;37m%*.d / 365, %d day%s left" , offset , day , 365 - day , day == 364 ? "" : "s");

	// Debug:
	// printf("columns: %d\n", columns);
	// printf("day: %7d\n", day);
	// If the program failed and the debug ahead didn't, the problem must be the escape characters used, check if your terminal can handle the colored text

	printf("%*.s%d%%\e[m\n" , columns / 2 - offset - 19 , "" , (int)(ratio * 100));
	printf(" %s%*.s\e[m%*.s \n" , color  , (int)ceil(ratio * columns) , "" , (int)floor((1 - ratio) * columns) , "");

	return 0;  // make sure your main returns int
}
