.DEFAULT_GOAL = loadingnewyear
.PHONY = clean
.PHONY = install

CC = gcc # clang tcc
CFLAGS = -O2 -Wall -Wextra -std=c11
LDFLAGS = -lm # Unused
OBJECTS = loadingnewyear.o terminal.o time.o


loadingnewyear: $(OBJECTS)
	$(CC) $(LDFLAGS) -o loadingnewyear $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm $(OBJECTS) 2> /dev/null || exit 0

install: loadingnewyear
	@sudo cp loadingnewyear /usr/bin/ && \
		echo "Installed, Thank you!" || \
		echo "Problem Installing."
