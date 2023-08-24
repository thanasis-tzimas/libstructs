#ifndef LIBSTRUCTS_graph_h
#define LIBSTRUCTS_graph_h

#include "types.h"
#include <stddef.h>
#include <stdlib.h>

#define GRAPH_INITIAL_SIZE 10
#define GRAPH_GROWTH_FACTOR 2

#define graph_init() \
	{ .links = NULL, .sp = 0, .size = GRAPH_INITIAL_SIZE }

/*
 * graph_add - add a new node to another known node
 * @new: the new node to be added
 * @node: the known node
 */
extern void graph_add(struct graph_node* new,
		      struct graph_node* node);

/*
 * graph_del - delete a node
 * @node: the node to be deleted
 */
extern void graph_del(struct graph_node *node);

#endif
