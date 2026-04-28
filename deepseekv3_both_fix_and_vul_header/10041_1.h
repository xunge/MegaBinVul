#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

typedef struct plist_data_s *plist_data_t;
typedef struct plist_node_s *plist_t;

struct plist_data_s {
    int type;
    char *strval;
    size_t length;
};

#define PLIST_STRING 1
#define PLIST_BIN_ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static plist_data_t plist_new_plist_data(void);
static void plist_free_data(plist_data_t data);
static plist_t node_create(void *parent, plist_data_t data);