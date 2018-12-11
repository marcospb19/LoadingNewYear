#include <stdio.h>
#include <stdlib.h>
#include "source/terminal.h"

int main()
{
	int columns = getWindowSize();

	int day = getDayOfYear();

	printf("columns: %d\n", columns);
	printf("day: %7d\n", day);

	return 0;  // make sure your main returns int
}
