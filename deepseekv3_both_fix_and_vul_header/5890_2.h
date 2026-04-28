#include <assert.h>
#include <stdio.h>

struct key {
    int serial;
    int datalen;
    struct {
        int write;
    } sem;
};

struct keyring_index_key {
    struct {
        const char *name;
    } *type;
};

struct assoc_array_edit {
    int dead_leaf;
};

extern struct {
    int write;
} keyring_serialise_link_sem;

extern struct {
    const char *name;
} key_type_keyring;

extern void kenter(const char *fmt, ...);
extern void key_payload_reserve(struct key *keyring, int datalen);
extern void assoc_array_cancel_edit(struct assoc_array_edit *edit);

#define BUG_ON(cond) assert(!(cond))
#define up_write(sem) ((sem)->write = 0)
#define KEYQUOTA_LINK_BYTES 0
#define __releases(x)