#include "htab.h"

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

unsigned htab_hash(unsigned long val, unsigned bits)
{
	return val * GOLDEN_RATIO >> (64 - bits);
}

void htab_init(struct bucket *ht, unsigned size)
{
	unsigned i;

	for (i = 0; i < size; i++)
		(&ht[i])->first = NULL;

}

void htab_add(struct bucket_entry *entry,
	struct bucket *ht,
	unsigned long key)
{
	bucket_add(entry, &ht[htab_hash(key, HTAB_BITS(ht))]);
}

void htab_del(struct bucket_entry *entry)
{
	bucket_del(entry);
}

int htab_is_empty(struct bucket *ht, unsigned size)
{
	unsigned i;

	for (i = 0; i < size; i++)
		if (!bucket_is_empty(&ht[i]))
			return -1;
	return 0;
}
