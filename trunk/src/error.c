#include "psyche.h"
#include "error.h"

static void error (int exit_status, const char *mode, const char *message);

static void 
error(int exit_status, const char *mode, const char *message)
{ 
	fprintf(stderr, "%s: %s: %s.\n", PSY_VERSION, mode, message); 
	if(exit_status >= 0) {
		endwin();
		exit(exit_status); 
	}
}

void 
psy_warning(const char *message) 
{ 
	error(-1, "Warning", message);
}

void 
psy_error(const char *message) 
{ 
	error(-1, "Error", message); 
}

void 
psy_fatal(const char *message)
{ 
	error(EXIT_FAILURE, "FATAL!", message); 
}
