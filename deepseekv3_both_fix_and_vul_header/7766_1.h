#include <stdbool.h>
#include <stdint.h>

#define R_API

typedef uint8_t ut8;

typedef struct RAnal {
    void *cxxabi;
    struct {
        int bits;
        bool big_endian;
    } *config;
    struct {
        char *arch;
    } *cur;
} RAnal;

typedef struct RVTableContext {
    RAnal *anal;
    void *abi;
    ut8 word_size;
    void *read_addr;
} RVTableContext;

bool vtable_read_addr_be8(void);
bool vtable_read_addr_le8(void);
bool vtable_read_addr_be16(void);
bool vtable_read_addr_le16(void);
bool vtable_read_addr_be32(void);
bool vtable_read_addr_le32(void);
bool vtable_read_addr_be64(void);
bool vtable_read_addr_le64(void);

bool r_str_startswith(const char *str, const char *prefix);