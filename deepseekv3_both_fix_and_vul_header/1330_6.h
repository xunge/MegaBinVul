#include <stdint.h>
#include <unistd.h>

#define PT_LOAD 1
#define PT_LOAD32 PT_LOAD

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
    
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS32 = 1,
        ELFDATA2LSB = 1,
        ELFDATA2MSB = 2,
        ET_DYN = 3
    };
} Elf32_Ehdr;

typedef struct {
    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_vaddr;
    uint32_t p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
    
    enum {
        PT_DYNAMIC = 2
    };
} Elf32_Phdr;

typedef struct {
    uint32_t sh_name;
    uint32_t sh_type;
    uint32_t sh_flags;
    uint32_t sh_addr;
    uint32_t sh_offset;
    uint32_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint32_t sh_addralign;
    uint32_t sh_entsize;
    
    enum {
        SHT_DYNSYM = 11
    };
} Elf32_Shdr;

typedef struct {
    int32_t d_tag;
    union {
        uint32_t d_val;
        uint32_t d_ptr;
    } d_un;
    
    enum {
        DT_NULL = 0,
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_HASH = 4,
        DT_GNU_HASH = 0x6ffffef5
    };
} Elf32_Dyn;

typedef struct {
    uint32_t st_name;
    uint32_t st_value;
    uint32_t st_size;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
} Elf32_Sym;

struct N_BELE_RTP {
    static const int be_policy;
    static const int le_policy;
};

struct InputFile {
    void seek(long, int);
    void readx(void *, unsigned);
};

enum {
    CMD_COMPRESS = 1
};

struct opt_t {
    int cmd;
};

struct PackLinuxElf32 {
    Elf32_Ehdr ehdri;
    Elf32_Phdr *phdri;
    Elf32_Shdr *shdri;
    Elf32_Shdr *sec_dynsym;
    Elf32_Shdr *sec_dynstr;
    Elf32_Dyn const *dynseg;
    char const *dynstr;
    Elf32_Sym const *dynsym;
    unsigned const *gashtab;
    unsigned const *hashtab;
    Elf32_Sym const *jni_onload_sym;
    uint32_t jni_onload_va;
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    unsigned sz_phdrs;
    unsigned long file_size;
    unsigned char *file_image;
    opt_t *opt;
    const int *bele;

    void PackLinuxElf32help1(InputFile *f);
    void alloc_file_image(unsigned char *&, unsigned);
    void throwCantUnpack(const char *);
    void throwCantPack(const char *);
    uint32_t check_pt_dynamic(Elf32_Phdr const *);
    void invert_pt_dynamic(Elf32_Dyn const *, uint32_t);
    void invert_pt_dynamic(Elf32_Dyn const *);
    void check_pt_load(Elf32_Phdr const *);
    Elf32_Shdr *elf_find_section_type(uint32_t);
    void *elf_find_dynamic(int32_t);
    Elf32_Sym const *elf_lookup(const char *);
    uint16_t get_te16(const void *);
    uint32_t get_te32(const void *);
};