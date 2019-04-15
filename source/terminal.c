#include <sys/ioctl.h> /* getWindowSize() */
#include <unistd.h>    /* getWindowSize() */
#include <time.h>      /* getDayOfYear ()  */


// Return the number of columns of the terminal
int getWindowSize()
{
	struct winsize terminalWindow;
	ioctl(STDOUT_FILENO , TIOCGWINSZ , &terminalWindow);
	return terminalWindow.ws_col;

	// From winsize struct:

	// struct winsize
	// {
	// 	unsigned short  ws_row;         /* rows, in characters */
	// 	unsigned short  ws_col;         /* columns, in characters */
	// 	unsigned short  ws_xpixel;      /* horizontal size, pixels - not used */
	// 	unsigned short  ws_ypixel;      /* vertical size, pixels - not used */
	// };
}


// Return the number of day of the year
int getDayOfYear()
{
	time_t rawTime = time(NULL);
	struct tm* timeinfo;
	timeinfo = localtime(&rawTime); // Fill the struct with actual time
	return timeinfo->tm_yday; // Return only the dayOfYear

	// From tm struct:

	// struct tm
	// {
	// 	int tm_sec;         /* seconds,  range 0 to 59          */
	// 	int tm_min;         /* minutes, range 0 to 59           */
	// 	int tm_hour;        /* hours, range 0 to 23             */
	// 	int tm_mday;        /* day of the month, range 1 to 31  */
	// 	int tm_mon;         /* month, range 0 to 11             */
	// 	int tm_year;        /* The number of years since 1900   */
	// 	int tm_wday;        /* day of the week, range 0 to 6    */
	// 	int tm_yday;        /* day in the year, range 0 to 365  */
	// 	int tm_isdst;       /* daylight saving time             */
	// };
}
