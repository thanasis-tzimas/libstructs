#include "log2.h"

int ilog2(unsigned long x)
{
	int bitpos = -1;
	asm("bsrq %1,%q0"
		: "+r" (bitpos)
		: "rm" (x));
	return bitpos + 1;
}
