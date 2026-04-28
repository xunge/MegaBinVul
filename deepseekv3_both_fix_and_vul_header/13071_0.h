#include <stdlib.h>
#include <string.h>

typedef struct tcpr_cidr_t {
    struct tcpr_cidr_t *next;
} tcpr_cidr_t;

extern void mask_cidr6(char **cidrin, char *delim);
extern tcpr_cidr_t *cidr2cidr(char *network);