#include <stdint.h>
#include <string.h>
#include <strings.h>

#define REF_TABLE_SIZE 256

struct link_ref {
    unsigned int id;
    struct {
        uint8_t *data;
        size_t size;
    } *label;
    struct link_ref *next;
};

unsigned int hash_link_ref(uint8_t *name, size_t length);