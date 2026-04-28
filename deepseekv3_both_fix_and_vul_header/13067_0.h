#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct tcpedit_portmap_t {
    struct tcpedit_portmap_t *next;
} tcpedit_portmap_t;

extern char *safe_strdup(const char *);
extern void safe_free(void *);
extern tcpedit_portmap_t *ports2PORT(const char *);