#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

typedef uint64_t upx_uint64_t;
typedef unsigned char upx_byte;

struct b_info {
    unsigned sz_unc;
    unsigned sz_cpr;
    unsigned char b_cto8;
};

struct l_info {
    unsigned short l_lsize;
};

struct p_info {
    unsigned p_filesize;
    unsigned p_blocksize;
};

struct PackHeader {
    unsigned u_len;
    unsigned c_len;
    unsigned filter_cto;
    unsigned c_adler;
    unsigned u_adler;
    unsigned getPackHeaderSize() const { return 0; }
};

struct Elf64_Ehdr {
    unsigned char e_ident[16];
    unsigned short e_type;
    unsigned short e_machine;
    unsigned int e_version;
    unsigned long e_entry;
    unsigned long e_phoff;
    unsigned long e_shoff;
    unsigned int e_flags;
    unsigned short e_ehsize;
    unsigned short e_phnum;
    unsigned short e_shnum;
    unsigned short e_shstrnd;
    enum {
        EI_OSABI = 7,
        EM_386 = 3,
        EM_PPC64 = 21
    };
};

struct Elf64_Phdr {
    unsigned int p_type;
    unsigned int p_flags;
    unsigned long p_offset;
    unsigned long p_vaddr;
    unsigned long p_paddr;
    unsigned long p_filesz;
    unsigned long p_memsz;
    unsigned long p_align;
    enum {
        PT_LOAD = 1,
        PT_DYNAMIC = 2,
        PF_X = 1
    };
};

struct Elf64_Dyn {
    unsigned long d_tag;
    union {
        unsigned long d_val;
        unsigned long d_ptr;
    } d_un;
    enum {
        DT_INIT = 12
    };
};

#define PT_LOAD64 Elf64_Phdr::PT_LOAD
#define OVERHEAD 1024
#define UPX_MAGIC_LE32 0x21585055
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

class OutputFile {
public:
    void seek(long offset, int whence) {}
    void write(const void *buf, unsigned len) {}
    void rewrite(const void *buf, unsigned len) {}
    void seek(long offset) {}
};

class InputFile {
public:
    void seek(long offset, int whence) {}
    void readx(void *buf, unsigned len) {}
};

class MemBuffer {
public:
    unsigned char *getPtr() { return nullptr; }
    unsigned char *operator+(unsigned offset) { return getPtr() + offset; }
    operator unsigned char*() { return getPtr(); }
    operator const void*() { return getPtr(); }
    unsigned getSize() const { return 0; }
    void alloc(unsigned size) {}
};

unsigned upx_adler32(const void *buf, unsigned len) { return 0; }
unsigned get_te16(const void *p) { return 0; }
unsigned get_te32(const void *p) { return 0; }
uint64_t get_te64(const void *p) { return 0; }
unsigned get_le32(const void *p) { return 0; }
unsigned up4(unsigned x) { return 0; }
void funpad4(InputFile *fi) {}
bool mem_size_valid(unsigned a, unsigned b, unsigned c) { return true; }
void throwCantUnpack(const char *msg) {}
void throwCompressedDataViolation() {}
void throwEOFException() {}
void throwChecksumError() {}

unsigned find_LOAD_gap(const Elf64_Phdr *phdr, unsigned j, unsigned u_phnum) { return 0; }
void decompress(MemBuffer &ibuf, upx_byte *ehdr, bool) {}
void unpackExtent(unsigned u_len, OutputFile *fo, unsigned &total_in, unsigned &total_out,
                 unsigned &c_adler, unsigned &u_adler, bool first_PF_X, unsigned szb_info,
                 bool phdr_offset_not_hi = false) {}

struct PackLinuxElf64 {
    InputFile *fi;
    OutputFile *fo;
    off_t file_size;
    off_t overlay_offset;
    unsigned blocksize;
    unsigned lsize;
    Elf64_Ehdr ehdri;
    Elf64_Phdr *phdri;
    l_info linfo;
    p_info hbuf;
    b_info bhdr;
    PackHeader ph;
    MemBuffer ibuf;
    upx_uint64_t load_va;
    unsigned long e_phoff;
    bool elf_find_ptype(unsigned type, const Elf64_Phdr *phdr, unsigned count) { return false; }
    void unpack(OutputFile *fo);
};