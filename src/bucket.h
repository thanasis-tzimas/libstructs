#ifndef LIBSTRUCTS_bucket_h
#define LIBSTRUCTS_bucket_h

#include <stddef.h>

struct bucket {
	struct bucket_entry *first;
};

struct bucket_entry {
	struct bucket_entry *next, **pprev;
};

/*
 * bucket_add - add an entry into a bucket
 * @new: the new entry
 * @bucket: the bucket that will accommodate the new entry
 */
extern void bucket_add(struct bucket_entry *new,
		       struct bucket *bucket);

/*
 * bucket_add_before - add an entry before an other entry
 * @new: the new entry
 * @next: the entry next to the new one
 */
extern void bucket_add_before(struct bucket_entry *new,
			      struct bucket_entry *next);

/*
 * bucket_add_after - add an entry after an other entry
 * @new: the new entry
 * @prev: the entry previous to the new one
 */
extern void bucket_add_after(struct bucket_entry *new,
			     struct bucket_entry *prev);

/*
 * bucket_del - delete a bucket from a bucket
 * @entry: the deleted bucket entry
 */
extern void bucket_del(struct bucket_entry *entry);

/*
 * bucket_is_empty - test if bucket has no entries
 * @bucket: the bucket to test
 */
extern int bucket_is_empty(struct bucket *bucket);

#endif
