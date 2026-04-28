#include <cstdint>
#include <cstdlib>
#include <cstdio>

#define SEEK_SET 0
#define CMD_COMPRESS 1
#define PT_LOAD32 0x70000000

struct InputFile {
    void seek(long, int);
    void readx(void*, unsigned);
};

struct N_BELE_RTP {
    static const int be_policy;
    static const int le_policy;
};

struct opt_t {
    int cmd;
};

struct Elf32_Ehdr {
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS32 = 1,
        ELFDATA2LSB = 1,
        ELFDATA2MSB = 2,
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
        PT_DYNAMIC = 2,
        PT_LOAD = 1
    };
    uint32_t p_type;
};

struct Elf32_Shdr {
    enum {
        SHT_DYNSYM = 11
    };
    uint32_t sh_link;
    uint32_t sh_type;
};

struct Elf32_Dyn {
    enum {
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_GNU_HASH = 0x6ffffef5,
        DT_HASH = 4
    };
};

struct Elf32_Sym {
    uint32_t st_value;
};

class PackLinuxElf32 {
public:
    void PackLinuxElf32help1(InputFile* f);
private:
    Elf32_Ehdr ehdri;
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    unsigned sz_phdrs;
    unsigned long file_size;
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
    Elf32_Sym const* jni_onload_sym;
    uint32_t jni_onload_va;
    opt_t* opt;
    const void* bele;

    uint16_t get_te16(const void*);
    uint32_t get_te32(const void*);
    void throwCantUnpack(const char*);
    void throwCantPack(const char*);
    void alloc_file_image(void*&, unsigned);
    Elf32_Shdr* elf_find_section_type(uint32_t);
    void* elf_find_dynamic(uint32_t);
    Elf32_Sym const* elf_lookup(const char*);
    unsigned check_pt_dynamic(const Elf32_Phdr*);
    void invert_pt_dynamic(const Elf32_Dyn*);
    void check_pt_load(const Elf32_Phdr*);
};