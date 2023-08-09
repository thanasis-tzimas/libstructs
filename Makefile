CC 	= gcc -O -std=c90
CFLAGS 	= -Wall -Wextra -pedantic-errors \
	  -fpic
srcdir	= .
SRCS_C 	= $(wildcard $(srcdir)/*.c)
OBJS	= $(SRCS_C:.c=.o)
TARGET	= libstructs

.PHONY: all
all: $(OBJS)
	$(CC) $(CFLAGS) -shared -o $(TARGET).so $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	$(RM) *.o *.so
