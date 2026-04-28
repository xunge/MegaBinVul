#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;

struct RBuffer {
    ut8 *buf;
    size_t length;
    size_t size;
};

struct mach_header {
    uint32_t magic;
    uint32_t cputype;
    uint32_t cpusubtype;
    uint32_t filetype;
    uint32_t ncmds;
    uint32_t sizeofcmds;
    uint32_t flags;
};

struct mach_header_64 {
    uint32_t magic;
    uint32_t cputype;
    uint32_t cpusubtype;
    uint32_t filetype;
    uint32_t ncmds;
    uint32_t sizeofcmds;
    uint32_t flags;
    uint32_t reserved;
};

struct load_command {
    uint32_t cmd;
    uint32_t cmdsize;
};

struct segment_command {
    uint32_t cmd;
    uint32_t cmdsize;
    char segname[16];
    uint32_t vmaddr;
    uint32_t vmsize;
    uint32_t fileoff;
    uint32_t filesize;
    uint32_t maxprot;
    uint32_t initprot;
    uint32_t nsects;
    uint32_t flags;
};

struct section {
    char sectname[16];
    char segname[16];
    uint32_t addr;
    uint32_t size;
    uint32_t offset;
    uint32_t align;
    uint32_t reloff;
    uint32_t nreloc;
    uint32_t flags;
    uint32_t reserved1;
    uint32_t reserved2;
};

struct symtab_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t symoff;
    uint32_t nsyms;
    uint32_t stroff;
    uint32_t strsize;
};

struct dysymtab_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t ilocalsym;
    uint32_t nlocalsym;
    uint32_t iextdefsym;
    uint32_t nextdefsym;
    uint32_t iundefsym;
    uint32_t nundefsym;
    uint32_t tocoff;
    uint32_t ntoc;
    uint32_t modtaboff;
    uint32_t nmodtab;
    uint32_t extrefsymoff;
    uint32_t nextrefsyms;
    uint32_t indirectsymoff;
    uint32_t nindirectsyms;
    uint32_t extreloff;
    uint32_t nextrel;
    uint32_t locreloff;
    uint32_t nlocrel;
};

struct dyld_info_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t rebase_off;
    uint32_t rebase_size;
    uint32_t bind_off;
    uint32_t bind_size;
    uint32_t weak_bind_off;
    uint32_t weak_bind_size;
    uint32_t lazy_bind_off;
    uint32_t lazy_bind_size;
    uint32_t export_off;
    uint32_t export_size;
};

struct dyld_cache_image_info {
    uint64_t address;
    uint64_t modTime;
    uint64_t inode;
    uint32_t pathFileOffset;
    uint32_t pad;
};

struct r_bin_dyldcache_lib_t {
    struct RBuffer *b;
    char path[1024];
    ut64 offset;
    int size;
};

struct r_bin_dyldcache_obj_t {
    struct RBuffer *b;
    char *file;
    ut64 size;
    int nlibs;
    struct {
        ut64 startaddr;
        ut64 baseaddroff;
    } hdr;
};

#define MH_MAGIC 0xfeedface
#define MH_MAGIC_64 0xfeedfacf
#define LC_SEGMENT 0x1
#define LC_SYMTAB 0x2
#define LC_DYSYMTAB 0xb
#define LC_DYLD_INFO 0x22
#define LC_DYLD_INFO_ONLY 0x80000022

#define R_NEW0(x) calloc(1, sizeof(x))
#define NZ_OFFSET(x) x += linkedit_offset

void eprintf(const char *fmt, ...);
struct RBuffer *r_buf_new(void);
void r_buf_set_bytes(struct RBuffer *buf, const ut8 *data, size_t len);
void r_buf_append_bytes(struct RBuffer *buf, const ut8 *data, size_t len);
void r_buf_free(struct RBuffer *buf);
void r_bin_dyldcache_apply_patch(struct RBuffer *buf, ut64 offset, ut64 value);

typedef struct RBuffer RBuffer;