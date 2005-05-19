#include "psyche.h"
#include "utils.h"
#include "workspace.h"

PSY_WSPACE *
workspace_create(const char *name)
{
	PSY_WSPACE *new;
	
	assert(name);
	
	new = (PSY_WSPACE *)xmalloc(sizeof(PSY_WSPACE));
	new->name = strdup(name);

	return new;
}

void
workspace_free(PSY_WSPACE *morituro) 
{
	PSY_WIN *cut;

	cut = morituro->head;
	
	while (cut!=NULL) {
		window_del(cut);
		cut->next;
	}
	
	free(morituro);
}
