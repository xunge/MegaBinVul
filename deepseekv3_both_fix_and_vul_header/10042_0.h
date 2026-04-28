#include <stdint.h>
#include <stddef.h>

#define BPLIST_MASK 0xF0
#define BPLIST_FILL 0x0F
#define BPLIST_UINT 0x10
#define BPLIST_NULL 0x00
#define BPLIST_TRUE 0x09
#define BPLIST_FALSE 0x08
#define BPLIST_REAL 0x20
#define BPLIST_DATE 0x30
#define BPLIST_DATA 0x40
#define BPLIST_STRING 0x50
#define BPLIST_UNICODE 0x60
#define BPLIST_ARRAY 0xA0
#define BPLIST_SET 0xC0
#define BPLIST_DICT 0xD0
#define BPLIST_UID 0x80

#define PLIST_BOOLEAN 1
#define TRUE 1
#define FALSE 0

typedef void* plist_t;
typedef struct plist_data* plist_data_t;

struct plist_data {
    int type;
    int boolval;
    size_t length;
};

struct bplist_data {
    const char* offset_table;
};

plist_data_t plist_new_plist_data(void);
plist_t node_create(void*, plist_data_t);
plist_t parse_uint_node(const char**, uint64_t);
plist_t parse_real_node(const char**, uint64_t);
plist_t parse_date_node(const char**, uint64_t);
plist_t parse_data_node(const char**, uint64_t);
plist_t parse_string_node(const char**, uint64_t);
plist_t parse_unicode_node(const char**, uint64_t);
plist_t parse_array_node(struct bplist_data*, const char**, uint64_t);
plist_t parse_uid_node(const char**, uint64_t);
plist_t parse_dict_node(struct bplist_data*, const char**, uint64_t);

#define PLIST_BIN_ERR(fmt, ...)
#define UINT_TO_HOST(ptr, size) 0