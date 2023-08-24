#include "bucket.h"

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

