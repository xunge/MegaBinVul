#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct state {
    const char *pos;
};

#define STREQLEN(s1, s2, len) (strncmp(s1, s2, len) == 0)
#define STATE_ERROR(state, err) 
#define STATE_ENOMEM 
#define PATHX_ENAME 0

static const char name_follow[] = "";