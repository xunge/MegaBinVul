#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define UT32_MAX 0xFFFFFFFFU
#define SHN_UNDEF 0
#define PFMT64x "llx"

#define R_FREE(x) free(x)
#define R_LOG_ERROR(...)
#define R_LOG_DEBUG(...)
#define r_return_val_if_fail(cond, val) if (cond) return val
#define r_sys_perror(x) perror(x)

typedef uint16_t Elf_Half;
typedef uint8_t ut8;
typedef uint32_t ut32;
typedef uint64_t ut64;

typedef struct {
    Elf_Half e_shstrndx;
} Elf_Ehdr;

typedef struct {
    ut64 sh_offset;
    ut64 sh_size;
} Elf_Shdr;

typedef struct {
    ut8 *shstrtab;
    ut64 shstrtab_size;
    Elf_Shdr *shstrtab_section;
    Elf_Shdr *strtab_section;
    Elf_Shdr *shdr;
    Elf_Ehdr ehdr;
    ut64 size;
    void *b;
    void *kv;
    bool strtab;
} ELFOBJ;

typedef struct {
    int (*num_set)(void *kv, const char *key, ut64 value, int unused);
} sdb;

static int is_shidx_valid(ELFOBJ *bin, Elf_Half shstrndx) {
    return 0;
}

static int sdb_num_set(void *kv, const char *key, ut64 value, int unused) {
    return 0;
}

static int r_buf_read_at(void *b, ut64 offset, ut8 *buf, ut64 size) {
    return 0;
}

#define Elf_(x) Elf_##x