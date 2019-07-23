#include <time.h> /* get_day_of_year() */


// Return the number of day of the year
int get_day_of_year()
{
	time_t raw_time = time(NULL);
	struct tm* time_info = localtime(&raw_time); // Get time information
	return time_info->tm_yday + 1; // Return the year day
}
