#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

typedef struct tcpr_list_t {
    unsigned long long min;
    unsigned long long max;
    struct tcpr_list_t *next;
} tcpr_list_t;

#define EBUF_SIZE 256

tcpr_list_t *new_list(void);