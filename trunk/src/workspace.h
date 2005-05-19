#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "windows.h"

typedef struct {
	char *name;
	PSY_WIN *head;
} PSY_WSPACE;

PSY_WSPACE *workspace_create(const char *name);
void workspace_free(PSY_WSPACE *morituro);

#endif /* WORKSPACE_H */
