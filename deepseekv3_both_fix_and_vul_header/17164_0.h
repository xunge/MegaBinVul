#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

#define INVALID_UGID ((uid_t)-1)

uid_t id_or_max(const char *name);