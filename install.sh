#!/bin/bash

printf "\e[36;1m" && \time -f " Time: %es" gcc -Werror -Wall source/terminal.c main.c -o loadingnewyear -lm && printf " Build successful\n"
