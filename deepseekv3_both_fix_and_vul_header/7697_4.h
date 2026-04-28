#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define R_BIN_ELF64 1
#define R_LOG_ERROR(x)
#define R_FREE(x) free(x)
#define READ32(x, y) (*(uint32_t*)((x) + (y)), (y) += 4)
#define R_BIN_ELF_READWORD(x, y) (*(uint64_t*)((x) + (y)), (y) += 8)

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct {
    uint64_t e_phoff;
} Elf_Ehdr;

typedef struct {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf_Phdr;

typedef struct {
    void *b;
    Elf_Ehdr ehdr;
    Elf_Phdr *phdr;
} ELFOBJ;

#define Elf_(x) x
#define Phdr Elf_Phdr
#define PT_PHDR 6

uint64_t r_bin_elf_get_phnum(ELFOBJ *bin);
uint64_t r_bin_elf_get_baddr(ELFOBJ *bin);
uint64_t r_bin_elf_v2p(ELFOBJ *bin, uint64_t addr);
int r_buf_read_at(void *b, size_t offset, void *buf, size_t len);