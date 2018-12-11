#!/bin/bash

# \time -f " Time: %es" gcc -Werror -Wall source/terminal.c main.c -o loadingnewyear -lm && printf " Build successful\n\n" && ./loadingnewyear
gcc -Werror -Wall source/terminal.c main.c -o loadingnewyear -lm
