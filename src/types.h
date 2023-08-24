#ifndef LIBSTRUCTS_types_h
#define LIBSTRUCTS_types_h

struct list_entry {
	struct list_entry *next, *prev;
};

struct bucket {
	struct bucket_entry *first;
};

struct bucket_entry {
	struct bucket_entry *next, **pprev;
};

struct graph_node {
	struct graph_node **links;
	unsigned int sp;
	unsigned int size;
};

#endif
