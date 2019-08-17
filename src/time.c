// nanosleep include warnings
#define _XOPEN_SOURCE 500

#include <time.h> /* get_day_of_year() , nanosleep() */


// Return the number of day of the year
int get_day_of_year()
{
	time_t raw_time = time(NULL);
	struct tm* time_info = localtime(&raw_time); // Get time information
	return time_info->tm_yday + 1; // Return the year day
}

void msleep(long milliseconds)
{
	struct timespec ts;

	ts.tv_sec  =  milliseconds / 1000;
	ts.tv_nsec = (milliseconds % 1000) * 1000 * 1000;

	nanosleep(&ts , &ts);
}
