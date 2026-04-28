#include <cstdint>
#include <cstring>
#include <cstdio>

#define SEEK_SET 0
#define PT_LOAD64 1

typedef uint64_t upx_uint64_t;
typedef uintptr_t upx_uintptr_t;

template<typename T>
static inline T umin(T a, T b) { return a < b ? a : b; }

struct InputFile {
    void seek(int, int);
    void readx(void *, unsigned);
};

struct N_BELE_RTP {
    static const int be_policy;
    static const int le_policy;
};

struct Elf64_Ehdr {
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS64 = 2,
        ELFDATA2LSB = 1,
        ELFDATA2MSB = 2,
        ET_DYN = 3
    };
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint16_t e_phentsize;
};

struct Elf64_Phdr {
    enum {
        PT_DYNAMIC = 2,
        PT_LOAD = 1
    };
    uint32_t p_type;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint32_t p_flags;
    uint64_t p_align;
};

struct Elf64_Shdr {
    enum {
        SHT_DYNSYM = 11
    };
    uint32_t sh_name;
    uint32_t sh_type;
    uint64_t sh_flags;
    uint64_t sh_addr;
    uint64_t sh_offset;
    uint64_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint64_t sh_addralign;
    uint64_t sh_entsize;
};

struct Elf64_Dyn {
    enum {
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_HASH = 4,
        DT_GNU_HASH = 0x6ffffef5
    };
    int64_t d_tag;
    union {
        uint64_t d_val;
        uint64_t d_ptr;
    } d_un;
};

struct Elf64_Sym {
    uint32_t st_name;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
    uint64_t st_value;
    uint64_t st_size;
};

struct PackLinuxElf64 {
    enum {
        CMD_COMPRESS = 1
    };
    struct options {
        int cmd;
    } *opt;
    unsigned long file_size;
    unsigned char *file_image;
    Elf64_Ehdr ehdri;
    Elf64_Phdr *phdri;
    Elf64_Shdr *shdri;
    Elf64_Shdr *sec_dynsym;
    Elf64_Shdr *sec_dynstr;
    Elf64_Dyn const *dynseg;
    char const *dynstr;
    Elf64_Sym const *dynsym;
    unsigned const *gashtab;
    unsigned const *hashtab;
    Elf64_Sym const *jni_onload_sym;
    uint64_t jni_onload_va;
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint64_t e_phoff;
    uint64_t e_shoff;
    unsigned sz_phdrs;
    unsigned sz_elf_hdrs;
    void *bele;

    uint16_t get_te16(const void *);
    uint32_t get_te32(const void *);
    uint64_t get_te64(const void *);
    void throwCantUnpack(const char *);
    void throwCantPack(const char *);
    void alloc_file_image(unsigned char *&, unsigned);
    upx_uint64_t check_pt_dynamic(Elf64_Phdr const *);
    void invert_pt_dynamic(Elf64_Dyn const *, unsigned);
    void check_pt_load(Elf64_Phdr const *);
    void *elf_find_dynamic(int);
    Elf64_Shdr *elf_find_section_type(int);
    Elf64_Sym const *elf_lookup(const char *);
    void PackLinuxElf64help1(InputFile *f);
};