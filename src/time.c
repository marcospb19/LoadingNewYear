/* #define required for the nanosleep implementation */
#define _XOPEN_SOURCE 500

#include <time.h> /* get_day_of_year() , nanosleep() */


// Return the number of day of the year
int get_day_of_year()
{
	time_t raw_time = time(NULL);

	// Return only the year day (from the struct tm*)
	return localtime(&raw_time)->tm_yday + 1;
}


// Get how many days in the current year (considering leap years)
int quantity_of_days_in_the_year()
{
	time_t raw_time = time(NULL);

	// Return only the days quantity (if divisible by 4, is a leap year)
	return (localtime(&raw_time)->tm_year % 4 == 0 ? 366 : 365);
}


// *Properly* sleeps the program for passed milliseconds
void milliseconds_sleep(long milliseconds)
{
	struct timespec ts;

	ts.tv_sec  =  milliseconds / 1000;
	ts.tv_nsec = (milliseconds % 1000) * 1000 * 1000;

	nanosleep(&ts , &ts);
}
