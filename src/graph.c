#include "graph.h"

void graph_add(struct graph_node* new,
	       struct graph_node* node)
{
	unsigned int sp = node->sp;

	sp += 1;
	if (sp > node->size) {
		node->links = realloc(node->links,
			node->sp * GRAPH_GROWTH_FACTOR);
		node->sp += 1;
	}
	node->links[sp] = new;
}

void graph_del(struct graph_node *node)
{
	node->links = NULL;
}
