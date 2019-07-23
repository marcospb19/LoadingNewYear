#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // system()
#include <math.h>     // ceil() and floor()
#include "terminal.h" // get_window_width()
#include "time.h"     // get_day_of_year()

#define red      "\e[101;1m"
#define green    "\e[102;1m"
#define yellow   "\e[103;1m"
#define magenta  "\e[105;1m"
#define blue     "\e[106;1m"
#define resetColor "\e[0;1m"
#define bold_white "\e[1;37m"


int main(int argc , char* argv[])
{
	if (argc > 1)
	{
		fprintf(stderr, "LoadingNewYear don't support any arguments.\n");
		return 1;
	}


	int day = get_day_of_year();
	// Ratio represents how full the year is
	float ratio = day / 365.0;

	char color[10];

	// Pick the color of the bar
	strcpy(color ,
	ratio == 1  ? green   : // Fireworks!
	ratio > 0.8 ? blue    : // End is nearby...
	ratio > 0.5 ? yellow  : // Half done.
	day  <= 10  ? magenta : // First 10 days of the year.
	red);                   // Nothing to celebrate.

	int barWidth = get_window_width() - 2;
	int offset = 4; // Correction

	// First line output
	// Confusing piece of code that do some magic, sorry for the mess guys
	printf(bold_white "%*.d / 365, %d day%s left" , offset , day , 365 - day , day == 1 ? "" : "s");
	printf("%*.s%d%%\e[m\n" , barWidth / 2 - offset - 19 , "" , (int)(ratio * 100));
	printf(" %s" , color);


	// Second line, actually bar loading, with intervals between stdout flush
	for (int i = 0; i < (int)ceil(ratio * barWidth); ++i)
	{
		printf(" ");
		system("sleep 0.0148");
		fflush(stdout);
	}

	// Fill the remaining space with spaces for no reason
	printf(resetColor "%*.s \n" , (int)((1 - ratio) * barWidth) , "");

	return 0;
}
