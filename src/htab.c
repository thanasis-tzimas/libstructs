#include "hashtable.h"

void bucket_add(struct bucket_entry *new,
		struct bucket *bucket)
{
	struct bucket_entry *first = bucket->first;
	new->next = first;
	if (first)
		first->pprev = &new->next;
	bucket->first = new;
	new->pprev = &bucket->first;
}

void bucket_add_before(struct bucket_entry *new,
		       struct bucket_entry *next)
{
	new->pprev = next->pprev;
	new->next = next;
	next->pprev = &new->next;
	*(new->pprev) = new;
}

void bucket_add_after(struct bucket_entry *new,
		      struct bucket_entry *prev)
{
	new->next = prev->next;
	prev->next = new;
	new->pprev = &prev->next;
	if (new->next)
		new->next->pprev = &new->next;
}

void bucket_del(struct bucket_entry *entry)
{
	struct bucket_entry *next = entry->next;
	struct bucket_entry **pprev = entry->pprev;

	*pprev = next;
	if (next)
		next->pprev = pprev;
	next = NULL;
	pprev = NULL;
}

int bucket_is_empty(struct bucket *bucket)
{
	return !(bucket->first);
}

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
