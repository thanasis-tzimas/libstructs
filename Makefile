CC 	= gcc -O -std=c99
CFLAGS 	= -Wall -Wextra -pedantic-errors \
	  -fpic
CLIBS	= -lm
srcdir	= ./src
SRCS_C 	= $(wildcard $(srcdir)/*.c)
OBJS	= $(SRCS_C:.c=.o)
TARGET	= libstructs

.PHONY: all
all: $(OBJS)
	$(CC) $(CFLAGS) $(CLIBS) -shared -o $(TARGET).so $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CLIBS) -c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(srcdir)/*.o *.so
