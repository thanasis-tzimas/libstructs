CC 	= gcc -O -std=c99
CFLAGS 	= -Wall -Wextra -pedantic-errors \
	  -fpic -Wno-analyzer-allocation-size \
	  -Wno-analyzer-deref-before-check \
	  -Wno-analyzer-free-of-non-heap \
	  -Wno-analyzer-malloc-leak \
	  -Wno-analyzer-out-of-bounds \
	  -Wno-analyzer-possible-null-dereference \
	  -Wno-analyzer-null-dereference \
	  -Wno-analyzer-tainted-allocation-size \
	  -Wpointer-arith \
	  -Wcast-align \
	  -Wstrict-prototypes \
	  -Wstrict-overflow=5 \
	  -Waggregate-return \
	  -Wswitch-default \
	  -Wconversion \
	  -fsanitize=address
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
