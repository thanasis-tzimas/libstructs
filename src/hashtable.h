#ifndef LIBSTRUCTS_hashtable_h
#define LIBSTRUCTS_hashtable_h

#include "log2.h"
#include <stddef.h>

struct bucket_entry {
	struct bucket_entry *next, **pprev;
};

struct bucket {
	struct bucket_entry *first;
};

#define BUCKET_INIT { .first = NULL }

#define DECLARE_HASHTABLE(name, bits) \
	struct bucket name[1 << (bits)]

#define DEFINE_HASHTABLE(name, bits) \
	DECLARE_HASHTABLE(name, bits) = \
		{ [0 ... ((1 << (bits)) - 1] = BUCKET_INIT }

#define ARRAY_SIZE(name) sizeof(name) / sizeof((name)[0])

#define HASHTABLE_SIZE(name) (ARRAY_SIZE(name))

#define HASHTABLE_BITS(name) ilog2(HASHTABLE_SIZE(name))

#define GOLDEN_RATIO 0x61c88647

#define bucket_is_empty(bucket) \
	!(bucket->first)
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
