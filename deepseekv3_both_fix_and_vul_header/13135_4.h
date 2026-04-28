#include <stdint.h>
#include <unistd.h>

typedef uint16_t Elf64_Half;
typedef uint32_t Elf64_Word;
typedef int32_t Elf64_Sword;
typedef uint64_t Elf64_Addr;
typedef uint64_t Elf64_Off;
typedef uint64_t Elf64_Xword;

struct Elf64_Ehdr {
    unsigned char e_ident[16];
    Elf64_Half e_type;
    Elf64_Half e_machine;
    Elf64_Word e_version;
    Elf64_Addr e_entry;
    Elf64_Off e_phoff;
    Elf64_Off e_shoff;
    Elf64_Word e_flags;
    Elf64_Half e_ehsize;
    Elf64_Half e_phentsize;
    Elf64_Half e_phnum;
    Elf64_Half e_shentsize;
    Elf64_Half e_shnum;
    Elf64_Half e_shstrndx;
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS64 = 2,
        ELFDATA2LSB = 1,
        ELFDATA2MSB = 2,
        ET_DYN = 3
    };
};

struct Elf64_Phdr {
    Elf64_Word p_type;
    Elf64_Word p_flags;
    Elf64_Off p_offset;
    Elf64_Addr p_vaddr;
    Elf64_Addr p_paddr;
    Elf64_Xword p_filesz;
    Elf64_Xword p_memsz;
    Elf64_Xword p_align;
    enum {
        PT_LOAD = 1,
        PT_DYNAMIC = 2,
        PT_LOAD64 = 0x70000000
    };
};

#define PT_LOAD64 0x70000000

struct Elf64_Shdr {
    Elf64_Word sh_name;
    Elf64_Word sh_type;
    Elf64_Xword sh_flags;
    Elf64_Addr sh_addr;
    Elf64_Off sh_offset;
    Elf64_Xword sh_size;
    Elf64_Word sh_link;
    Elf64_Word sh_info;
    Elf64_Xword sh_addralign;
    Elf64_Xword sh_entsize;
    enum {
        SHT_DYNSYM = 11
    };
};

struct Elf64_Dyn {
    Elf64_Sword d_tag;
    union {
        Elf64_Xword d_val;
        Elf64_Addr d_ptr;
    } d_un;
    enum {
        DT_NULL = 0,
        DT_NEEDED = 1,
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_HASH = 4,
        DT_GNU_HASH = 0x6ffffef5
    };
};

struct Elf64_Sym {
    Elf64_Word st_name;
    unsigned char st_info;
    unsigned char st_other;
    Elf64_Half st_shndx;
    Elf64_Addr st_value;
    Elf64_Xword st_size;
};

typedef uint64_t upx_uint64_t;
typedef int64_t upx_int64_t;
typedef int32_t upx_int32_t;
typedef uint32_t upx_uint32_t;

struct N_BELE_RTP {
    static const int be_policy;
    static const int le_policy;
};

struct InputFile {
    void seek(long, int);
    void readx(void*, unsigned);
};

struct PackLinuxElf64 {
    void PackLinuxElf64help1(InputFile *f);
    void throwCantUnpack(const char*);
    void throwCantPack(const char*);
    void alloc_file_image(unsigned char*&, unsigned);
    Elf64_Shdr* elf_find_section_type(unsigned);
    void* elf_find_dynamic(unsigned);
    Elf64_Sym* elf_lookup(const char*);
    void check_pt_load(const Elf64_Phdr*);
    upx_uint64_t check_pt_dynamic(const Elf64_Phdr*);
    void invert_pt_dynamic(const Elf64_Dyn*);
    
    Elf64_Ehdr ehdri;
    Elf64_Phdr* phdri;
    Elf64_Shdr* shdri;
    Elf64_Shdr* sec_dynsym;
    Elf64_Shdr* sec_dynstr;
    const Elf64_Dyn* dynseg;
    const char* dynstr;
    const Elf64_Sym* dynsym;
    const unsigned* gashtab;
    const unsigned* hashtab;
    const Elf64_Sym* jni_onload_sym;
    upx_uint64_t jni_onload_va;
    upx_uint64_t e_phoff;
    upx_uint64_t e_shoff;
    unsigned sz_phdrs;
    unsigned e_type;
    unsigned e_phnum;
    unsigned e_shnum;
    unsigned char* file_image;
    unsigned long file_size;
    struct {
        int cmd;
    } *opt;
    const int* bele;
    enum {
        CMD_COMPRESS
    };
};

template<typename T> T get_te16(const T*);
template<typename T> T get_te32(const T*);
template<typename T> T get_te64(const T*);