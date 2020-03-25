#include <stdio.h>
#include <string.h>   // strcpy()
#include "terminal.h" // get_window_width()
#include "time.h"     // get_day_of_year(), milliseconds_sleep(), quantity_of_days_in_the_year()

#define red      "\e[101;1m"
#define green    "\e[102;1m"
#define yellow   "\e[103;1m"
#define magenta  "\e[105;1m"
#define blue     "\e[106;1m"
#define reset_color "\e[0;1m"
#define bold_white  "\e[1;37m"


int main(int argc , char* argv[])
{
	for (int i = 1 ; i < argc ; i++)
	{
		if (strcmp(argv[i] , "--help") == 0 ||
		    strcmp(argv[i] , "-h"    ) == 0)
		{
			puts("Software from https://github.com/marcospb19/LoadingNewYear.");
			puts("LoadingNewYear is a simple and animated colored bar that shows the year progress.");
			return 0;
		}
		else if (strcmp(argv[i] , "--version") == 0 ||
		         strcmp(argv[i] , "-V"       ) == 0)
		{
			puts("Software from https://github.com/marcospb19/LoadingNewYear.");
			return 0;
		}
		else
		{
			fprintf(stderr , "Argument not recognized \"%s\"\n" , argv[i]);
			return 1;
		}
	}

	int day = get_day_of_year();
	// Ratio represents how full the year is
	float ratio = day / 365.0;

	char progress_color[10];

	// Pick the color of the bar based on the year progress
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
	for (int i = 0 ; i < (int)(ratio * barWidth + 1) ; ++i)
	{
		printf(" ");
		fflush(stdout);
		milliseconds_sleep(20); // Sleeps for N milliseconds
	}

	// Reset the color and fill the remaining space with spaces
	printf(reset_color "%*.s \n" , (int)((1 - ratio) * barWidth) , "");

	return 0;
}
