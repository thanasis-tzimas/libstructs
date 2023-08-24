/*
 * list.h - doubly linked list struct and function definitions
 */
#ifndef LIBSTRUCTS_list_h
#define LIBSTRUCTS_list_h

#include "types.h"
#include <stddef.h>

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_entry name = LIST_HEAD_INIT(name)

/*
 * list_add_between - add a new entry between two known ones
 * @new: the entry to be added
 * @prev: the previous entry from the new one
 * @next: the next entry from the new one
 */
extern void list_add_between(struct list_entry *new,
		struct list_entry *prev,
		struct list_entry *next);

/*
 * list_add_after - add an entry after a known onw
 * @new: the entry to added
 * @entry: the known entry
 */
extern void list_add_after(struct list_entry *new,
		struct list_entry *entry);


/*
 * list_add_before - add an entry before a known one
 * @new: the entry to be added
 * @entry: the known entry
 */
extern void list_add_before(struct list_entry *new,
		struct list_entry *entry);


/*
 * list_add_tail - add an entry at the list's tail
 * @tail: the list's new tail
 * @head: the list's head
 */
#define list_add_tail(tail, head) \
	list_add_between(tail, head->prev, head)
/*
 * list_del - delete an entry from the list
 * @entry: the entry to be deleted
 */
extern void list_del(struct list_entry *entry);


/*
 * list_is_empty - test if list is empty
 * @head: the list's head to be tested
 */
extern int list_is_empty(struct list_entry *head);

/*
 * list_get - get the list's container as a pointer
 * @ptr:
 * @T:
 * @member:
 *
 * Note: this is not a type safe operation.
 */
#define list_get(ptr, T, member) \
	container_of(ptr, T, member)
#endif
