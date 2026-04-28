#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t ut32;
typedef int32_t st32;
typedef uint64_t ut64;
typedef uint8_t ut8;

struct relocation_info {
    ut32 r_address;
    ut32 r_symbolnum;
    ut32 r_type;
    bool r_extern;
    bool r_pcrel;
    ut32 r_length;
};

struct reloc_t {
    ut64 addr;
    ut32 offset;
    ut32 ord;
    ut32 type;
    bool external;
    bool pc_relative;
    ut32 size;
    char name[256];
};

struct MACH0_obj_t {
    ut64 size;
    void *b;
    ut32 nsymtab;
    struct nlist *symtab;
};

struct nlist {
    ut32 n_strx;
};

typedef struct RSkipList RSkipList;

#define R_NEW0(type) calloc(1, sizeof(type))
void r_skiplist_insert(RSkipList *list, void *data);
void r_str_ncpy(char *dst, const char *src, size_t n);
char *get_name(struct MACH0_obj_t *bin, ut32 stridx, bool demangle);
ut64 offset_to_vaddr(struct MACH0_obj_t *bin, ut32 offset);
size_t r_buf_read_at(void *b, ut64 offset, ut8 *buf, size_t size);

#define MACH0_(x) MACH0_##x
typedef struct MACH0_obj_t MACH0_(obj_t);