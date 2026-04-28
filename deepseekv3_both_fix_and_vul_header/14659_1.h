#include <stdint.h>
#include <stdio.h>

#define PLIST_DICT 1
#define PLIST_KEY 2
#define PLIST_STRING 3

typedef struct plist_data_s* plist_data_t;
typedef struct plist_node_s* plist_t;

struct bplist_data {
    const char *data;
    uint64_t size;
    uint64_t num_objects;
    uint64_t dict_size;
};

struct plist_data_s {
    int type;
    uint64_t length;
    char *strval;
};

struct plist_node_s {
    plist_data_t data;
};

plist_t node_create(void*, plist_data_t);
void node_attach(plist_t, plist_t);
void plist_free(plist_t);
plist_data_t plist_new_plist_data(void);
plist_data_t plist_get_data(plist_t);
plist_t parse_bin_node_at_index(struct bplist_data*, uint64_t);
uint64_t UINT_TO_HOST(const char*, uint64_t);