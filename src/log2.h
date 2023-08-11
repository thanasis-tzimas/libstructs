#ifndef LIBSTRUCTS_log2_h
#define LIBSTRUCTS_log2_h

static inline int ilog2(unsigned long x)
{
	int i, y;

	y = 0;
	for (i = 32; i > 0; i >>= 1)
		if ((1ul << (y + i)) <= x)
			y += i;
	return y + 1;
}

#endif
