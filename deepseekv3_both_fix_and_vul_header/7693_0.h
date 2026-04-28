#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint32_t ut32;
typedef uint8_t ut8;
typedef uint64_t ut64;

#define Elf_(x) Elf64_##x
#define Elf64_Shdr Elf64_Shdr
#define Elf32_Shdr Elf32_Shdr

typedef struct {
    ut32 e_shnum;
    ut64 e_shoff;
} Elf64_Ehdr;

typedef struct {
    ut32 sh_name;
    ut32 sh_type;
    ut64 sh_flags;
    ut64 sh_addr;
    ut64 sh_offset;
    ut64 sh_size;
    ut32 sh_link;
    ut32 sh_info;
    ut64 sh_addralign;
    ut64 sh_entsize;
} Elf64_Shdr;

typedef struct {
    ut32 sh_name;
    ut32 sh_type;
    ut32 sh_flags;
    ut32 sh_addr;
    ut32 sh_offset;
    ut32 sh_size;
    ut32 sh_link;
    ut32 sh_info;
    ut32 sh_addralign;
    ut32 sh_entsize;
} Elf32_Shdr;

#define R_BIN_ELF64 1
#define R_BIN_ELF_READWORD(buf, off) (*(ut64*)((buf) + (off)))
#define READ32(buf, off) (*(ut32*)((buf) + (off)))
#define UT32_MUL(a, b, c) (*(a) = (b) * (c), 1)
#define R_NEWS0(type, num) calloc(num, sizeof(type))
#define R_FREE(ptr) free(ptr)
#define r_return_val_if_fail(cond, val) if (!(cond)) return val
#define R_LOG_ERROR(fmt, ...) 
#define r_sys_perror(msg) 
#define PFMT64x "llx"

typedef struct {
    Elf64_Ehdr ehdr;
    Elf64_Shdr *shdr;
    size_t size;
    void *kv;
    void *b;
} ELFOBJ;