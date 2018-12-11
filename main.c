#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "source/terminal.h"

#define highlight "\033[102;9m"
#define endHighlight "\033[0m"

int main()
{
	int columns = getWindowSize() - 2;

	int day = getDayOfYear();
	printf("%d\n", day);

	// printf("columns: %d\n", columns);
	// printf("day: %7d\n", day);
	float ratio = day / 365.0;

	printf("%*.s%d%%\n" , columns / 2 - 2 , "" , (int)(ratio * 100));
	printf("[" highlight "%s%*.s" endHighlight "%*.s]\n" , ratio == 1 ? "" : "\033[103;9m" , (int)ceil(ratio * columns) , "" , (int)floor((1 - ratio) * columns) , "");

	return 0;  // make sure your main returns int
}
