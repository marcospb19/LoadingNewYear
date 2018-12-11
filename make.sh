#!/bin/bash

\time -f " Time: %es" gcc -Werror -Wall source/terminal.c main.c -o loadingnewyear && printf " Build successful\n\n" && ./loadyear
