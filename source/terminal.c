#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>

// Return the number of columns of the terminal
int getWindowSize()
{
	struct winsize terminalWindow;
	ioctl(STDOUT_FILENO , TIOCGWINSZ , &terminalWindow);
	return terminalWindow.ws_col;
	// *lines = terminalWindow.ws_row;
}

// Return the number of day of the year
int getDayOfYear()
{
	time_t rawTime = time(NULL);
	struct tm* timeinfo;
	timeinfo = localtime(&rawTime); // Fill the struct with actual time
	return timeinfo->tm_yday; // Return only the dayOfYear
}
