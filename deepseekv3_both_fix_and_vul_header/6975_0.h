#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>

struct InputFile {
    void seek(long, int);
    void readx(void*, unsigned);
};

struct N_BELE_RTP {
    static const int be_policy;
    static const int le_policy;
};

const int N_BELE_RTP::be_policy = 0;
const int N_BELE_RTP::le_policy = 1;

struct Elf32_Ehdr {
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS32 = 1,
        ELFDATA2MSB = 2,
        ELFDATA2LSB = 1,
        ET_DYN = 3
    };
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint16_t e_phentsize;
};

struct Elf32_Phdr {
    enum {
        PT_DYNAMIC = 2
    };
    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_vaddr;
    uint32_t p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
};

struct Elf32_Shdr {
    enum {
        SHT_DYNSYM = 11
    };
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
};

struct Elf32_Dyn {
    enum {
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_HASH = 4,
        DT_GNU_HASH = 0x6ffffef5
    };
    int32_t d_tag;
    union {
        uint32_t d_val;
        uint32_t d_ptr;
    } d_un;
};

struct Elf32_Sym {
    uint32_t st_name;
    uint32_t st_value;
    uint32_t st_size;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
};

enum Command {
    CMD_COMPRESS = 1
};

struct Options {
    Command cmd;
};

typedef uintptr_t upx_uintptr_t;

template<typename T>
inline T umin(T a, T b) { return a < b ? a : b; }

template<typename T1, typename T2>
inline auto umin(T1 a, T2 b) -> decltype(a < b ? a : b) {
    return a < b ? a : b;
}

template<typename T>
T get_te16(T* p) { return *p; }

template<typename T>
T get_te32(T* p) { return *p; }

#define usizeof(type) sizeof(type)

struct PackLinuxElf32 {
    void PackLinuxElf32help1(InputFile* f);
    void throwCantUnpack(const char*);
    void throwCantPack(const char*);
    void alloc_file_image(void*&, unsigned);
    unsigned check_pt_dynamic(Elf32_Phdr const*);
    void invert_pt_dynamic(Elf32_Dyn const*, unsigned);
    bool is_LOAD32(Elf32_Phdr const*);
    void check_pt_load(Elf32_Phdr const*);
    void* elf_find_dynamic(int);
    Elf32_Shdr* elf_find_section_type(int);
    Elf32_Sym* elf_lookup(const char*);
    
    Elf32_Ehdr ehdri;
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    unsigned sz_phdrs;
    unsigned long file_size;
    void* bele;
    void* file_image;
    Elf32_Phdr* phdri;
    Elf32_Shdr* shdri;
    Elf32_Shdr* sec_dynsym;
    Elf32_Shdr* sec_dynstr;
    Elf32_Dyn const* dynseg;
    char const* dynstr;
    Elf32_Sym const* dynsym;
    unsigned const* gashtab;
    unsigned const* hashtab;
    Elf32_Sym* jni_onload_sym;
    uint32_t jni_onload_va;
    Options* opt;
};