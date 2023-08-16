#ifndef LIBSTRUCTS_bucket_h
#define LIBSTRUCTS_bucket_h

struct bucket {
	struct bucket_entry *first;
};

struct bucket_entry {
	struct bucket_entry *next, **pprev;
};

/*
 * bucket_is_empty - test if bucket has no entries
 * @bucket: the bucket to test
 */
extern int bucket_is_empty(struct bucket *bucket);

#endif
