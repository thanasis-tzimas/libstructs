#include "list.h"

void list_add_between(struct list_entry *new,
		struct list_entry *prev,
		struct list_entry *next)
{
	prev->next = new;
	next->prev = new;
	new->prev = prev;
	new->next = next;
}

void list_add_after(struct list_entry *new,
	struct list_entry *entry)
{
	list_add_between(new, entry, entry->next);
}

void list_add_before(struct list_entry *new,
	struct list_entry *entry)
{
	list_add_between(new, entry->prev, entry);
}

void list_del(struct list_entry *entry)
{
	struct list_entry *prev = entry->prev;
	struct list_entry *next = entry->next;

	next->prev = prev;
	prev->next = next;

	entry->prev = NULL;
	entry->next = NULL;
}

int list_is_empty(struct list_entry *head)
{
	return !head->next == head;
}
