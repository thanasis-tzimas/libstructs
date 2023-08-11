#include "log2.h"

int ilog2(unsigned long x)
{
	int i, y;

	y = 0;
	for (i = 32; i > 0; i >>= 1)
		if ((1ul << (y + i)) <= x)
			y += i;
	return y + 1;
}
