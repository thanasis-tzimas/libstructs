#ifndef LIBSTRUCTS_container_of
#define LIBSTRUCTS_container_of

#ifdef offsetof
#undef offsetof
	#define offsetof(T, member) \
		((size_t)&(((T*)0)->member))
#endif

#define container_of(ptr, T, member) ({ \
	void *_vptr = (void*)(ptr); \
	((T*)(_vptr - offsetof(T, member))); })

#endif
