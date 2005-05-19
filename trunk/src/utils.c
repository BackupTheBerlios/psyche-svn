#include "psyche.h"
#include "utils.h"

void*
xmalloc(size_t size)
{
	void *new = malloc(size); 
	if(!new) 
		psy_fatal("Out of memory");
	return new;	
}

void*
xrealloc(void *ptr, size_t size)
{
	ptr = realloc(ptr, size); 
	if(!ptr) 
		psy_fatal("Out of memory");
	return ptr;	
}
