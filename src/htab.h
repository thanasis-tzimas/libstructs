#ifndef LIBSTRUCTS_hashtable_h
#define LIBSTRUCTS_hashtable_h

#include "types.h"
#include <math.h>
#include <stddef.h>

#define BUCKET_INIT { .first = NULL }

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

#define DECLARE_HASHTABLE(name, bits) \
	struct bucket name[1 << (bits)]

#define DEFINE_HASHTABLE(name, bits) \
	DECLARE_HASHTABLE(name, bits) = \
		{ [0 ... ((1 << (bits)) - 1] = BUCKET_INIT }

#define ARRAY_SIZE(name) sizeof(name) / sizeof((name)[0])

#define HASHTABLE_SIZE(name) (ARRAY_SIZE(name))

#define HASHTABLE_BITS(name) ilogb(HASHTABLE_SIZE(name))

#define GOLDEN_RATIO 0x61c88647

/*
 * hashtable_hash - a fast hash function for ints 
 *  by Nadia Yvette Chambers, IBM
 * @val: the value to be hashed
 * @bits: the nth most significant bits to be used on the calculation
 */
extern unsigned hashtable_hash(unsigned long val, unsigned bits);

/*
 * hashtable_init - initialize a hashtable
 * @ht: the hashstable to be initialized
 * @size: the hashtable's size
 */
extern void hashtable_init(struct bucket *ht, unsigned size);

/*
 * hashtable_add - add a bucket entry into a bucket in the hashtable
 * @entry: the entry to be added
 * @ht: the hashtable that the new entry will be added to
 * @key: the key that will be hashed and added as an entry in the hashtable
 */
extern void hashtable_add(struct bucket_entry *entry,
	struct bucket *ht,
	unsigned long key);

/*
 * hashtable_del - delete an entry from the hashtable
 * @entry: the bucket entry to be deleted
 */
extern void hashtable_del(struct bucket_entry *entry);

/*
 * hashtable_is_empty - test if hashtable is empty
 * @ht: the hashtable to be tested if empty
 * @size: the hashtable's size
 */
extern int hashtable_is_empty(struct bucket *ht, unsigned size);

#endif
