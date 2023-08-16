#include "hashtable.h"

unsigned hashtable_hash(unsigned long val, unsigned bits)
{
	return val * GOLDEN_RATIO >> (64 - bits);
}

void hashtable_init(struct bucket *ht, unsigned size)
{
	unsigned i;

	for (i = 0; i < size; i++)
		(&ht[i])->first = NULL;

}

void hashtable_add(struct bucket_entry *entry,
	struct bucket *ht,
	unsigned long key)
{
	struct bucket_entry *first = (&ht[hashtable_hash(key, HASHTABLE_BITS(ht))])->first;
	entry->next = first;
	if (first)
		first->pprev = &entry->next;
	(&ht[hashtable_hash(key, HASHTABLE_BITS(ht))])->first = entry;
	entry->pprev = &(&ht[hashtable_hash(key, HASHTABLE_BITS(ht))])->first;
}

void hashtable_del(struct bucket_entry *entry)
{
	entry->next = NULL;
	entry->pprev = NULL;
}

int hashtable_is_empty(struct bucket *ht, unsigned size)
{
	unsigned i;

	for (i = 0; i < size; i++)
		if (!bucket_is_empty(&ht[i]))
			return -1;
	return 0;
}
