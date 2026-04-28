#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grp.h>
#include <sys/types.h>

#define INVALID_UGID ((gid_t)-1)

extern gid_t id_or_max(const char *name);