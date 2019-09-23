#include <stdio.h>
#include <string.h>   // strcpy()
#include <stdlib.h>   // system()
#include <math.h>     // ceil() and floor()
#include "terminal.h" // get_window_width()
#include "time.h"     // get_day_of_year() and msleep()

#define red      "\e[101;1m"
#define green    "\e[102;1m"
#define yellow   "\e[103;1m"
#define magenta  "\e[105;1m"
#define blue     "\e[106;1m"
#define reset_color "\e[0;1m"
#define bold_white  "\e[1;37m"


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

	char progress_color[10];

	// Pick the color of the bar
	strcpy(progress_color ,
		ratio == 1  ? green   : // Fireworks!
		ratio > 0.8 ? blue    : // End is nearby...
		ratio > 0.5 ? yellow  : // Half done.
		day  <= 10  ? magenta : // First 10 days of the year.
		red);                   // Nothing to celebrate.

	int barWidth = get_window_width() - 2;
	int offset = 4; // Correction

	// First line output
	// Confusing piece of code that do some magic, sorry for the mess here

	// Change color and style to white and bold
	// This is the first line of the output, this information stands at the top
	printf(bold_white "%*.d / 365, %d day%s left" , offset , day , 365 - day , day == 1 ? "" : "s");
	printf("%*.s%d%%" , barWidth / 2 - offset - 19 , "" , (int)(ratio * 100));

	// Skips a line (go to the second line) and sets the progress_color
	printf("\n %s" , progress_color);

	// Bar loading with the animation and sleeps between
	for (int i = 0; i < (int)ceil(ratio * barWidth); ++i)
	{
		printf(" ");
		fflush(stdout);
		msleep(15); // Sleeps for 15 milliseconds
	}

	// Reset the color and fill the remaining space with spaces
	printf(reset_color "%*.s \n" , (int)((1 - ratio) * barWidth) , "");

	return 0;
}
