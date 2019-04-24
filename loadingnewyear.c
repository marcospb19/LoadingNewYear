#include <stdio.h>           // printf()
#include <string.h>          // strcpy()
#include <math.h>            // ceil() and floor()
#include "source/terminal.h" // getWindowWidth() and getDayOfYear()

#define red      "\e[101;1m"
#define green    "\e[102;1m"
#define yellow   "\e[103;1m"
#define magenta  "\e[105;1m"
#define blue     "\e[106;1m"
#define resetColor "\e[0;1m"

int main()
{
	// Ratio represents how full the year is
	int day = getDayOfYear();
	float ratio = day / 365.0;

	char color[10];
	strcpy(color ,
	ratio == 1  ? green   : // Fireworks!
	ratio > 0.8 ? blue    : // End is nearby...
	ratio > 0.5 ? yellow  : // Half done.
	day  <= 10  ? magenta : // First 10 days of the year.
	red);                   // Nothing to celebrate.

	int barWidth = getWindowWidth() - 2;
	int offset = 4;

	printf("\e[1;37m%*.d / 365, %d day%s left" , offset , day , 365 - day , day == 1 ? "" : "s");
	printf("%*.s%d%%\e[m\n" , barWidth / 2 - offset - 19 , "" , (int)(ratio * 100));
	printf(" %s%*.s\e[m%*.s \n" , color  , (int)ceil(ratio * barWidth) , "" , (int)floor((1 - ratio) * barWidth) , "");
	printf(resetColor);
}
