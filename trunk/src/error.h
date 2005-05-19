#ifndef ERROR_H
#define ERROR_H

#include <stdlib.h>
#include <assert.h>

void psy_warning(const char *message);
void psy_error(const char *message);
void psy_fatal(const char *message);

#endif /* ERROR_H */
