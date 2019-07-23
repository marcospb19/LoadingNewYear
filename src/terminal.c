#include <sys/ioctl.h> /* get_window_size() */
#include <unistd.h>    /* get_window_size() */


// Return the number of columns of the terminal
int get_window_width()
{
	struct winsize term_window;
	ioctl(STDOUT_FILENO , TIOCGWINSZ , &term_window);
	return term_window.ws_col;
}
