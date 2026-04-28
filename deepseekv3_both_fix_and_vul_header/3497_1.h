#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define POLICY_RDLOCK
#define POLICY_RDUNLOCK

struct policydb {
    struct {
        unsigned nprim;
    } p_bools;
    struct {
        int state;
    } **bool_val_to_struct;
    char **p_bool_val_to_name;
};

extern struct policydb policydb;

void *xmalloc_array(size_t size, size_t num);
void xfree(void *ptr);
size_t strlcpy(char *dest, const char *src, size_t size);

#define xmalloc_array(type, num) xmalloc_array(sizeof(type), num)