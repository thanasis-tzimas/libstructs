#include "bucket.h"

int bucket_is_empty(struct bucket *bucket)
{
	return !(bucket->first);
}

