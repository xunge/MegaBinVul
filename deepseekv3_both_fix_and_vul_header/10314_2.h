#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t ut8;
typedef uint32_t ut32;
typedef uint64_t ut64;

#define PFMT64x "llx"
#define MACH0_(x) x

#define LC_SEGMENT 0x1
#define LC_SYMTAB 0x2
#define LC_THREAD 0x4
#define LC_UNIXTHREAD 0x5
#define LC_LOAD_DYLIB 0xc
#define LC_ID_DYLIB 0xd
#define LC_LOAD_DYLINKER 0xe
#define LC_SEGMENT_64 0x19
#define LC_UUID 0x1b
#define LC_CODE_SIGNATURE 0x1d
#define LC_SEGMENT_SPLIT_INFO 0x1e
#define LC_REEXPORT_DYLIB 0x1f
#define LC_LOAD_WEAK_DYLIB 0x18
#define LC_DYLIB_CODE_SIGN_DRS 0x2b
#define LC_ENCRYPTION_INFO 0x21
#define LC_DYLD_INFO 0x22
#define LC_DYLD_INFO_ONLY 0x80000022
#define LC_VERSION_MIN_MACOSX 0x24
#define LC_VERSION_MIN_IPHONEOS 0x25
#define LC_FUNCTION_STARTS 0x26
#define LC_MAIN 0x28
#define LC_DATA_IN_CODE 0x29
#define LC_SOURCE_VERSION 0x2a
#define LC_ENCRYPTION_INFO_64 0x2c
#define LC_LINKER_OPTION 0x2d
#define LC_RPATH 0x8000001c
#define LC_VERSION_MIN_TVOS 0x2f
#define LC_VERSION_MIN_WATCHOS 0x30
#define LC_DYSYMTAB 0xb

struct load_command {
    uint32_t cmd;
    uint32_t cmdsize;
};

struct MACH0_(mach_header) {
    uint32_t magic;
    uint32_t cputype;
    uint32_t cpusubtype;
    uint32_t filetype;
    uint32_t ncmds;
    uint32_t sizeofcmds;
    uint32_t flags;
};

struct uuid_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint8_t uuid[16];
};

struct dylinker_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t name;
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

struct MACH0_(encryption_info_command) {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t cryptoff;
    uint32_t cryptsize;
    uint32_t cryptid;
};

struct MACH0_(obj_t) {
    struct MACH0_(mach_header) hdr;
    ut64 size;
    ut8 big_endian;
    void *b;
    void *kv;
    int uuidn;
    int os;
    int has_crypto;
    int nsegs;
    int nlibs;
    char *intrp;
    ut64 entry;
    struct load_command main_cmd;
    struct dyld_info_command *dyld_info;
};

int r_buf_read_at(void *b, ut64 off, ut8 *buf, int len);
int r_buf_fread_at(void *b, ut64 off, ut8 *buf, const char *fmt, int n);
void bprintf(const char *fmt, ...);
uint32_t r_read_ble32(const ut8 *buf, bool big_endian);
uint64_t r_read_ble64(const ut8 *buf, bool big_endian);
void r_hex_bin2str(const ut8 *bin, int len, char *str);
void *sdb_num_set(void *kv, const char *key, ut64 num, int mode);
void *sdb_set(void *kv, const char *key, const char *val, int mode);
char *sdb_fmt(int mode, const char *fmt, ...);
bool parse_segments(struct MACH0_(obj_t) *bin, ut64 off);
bool parse_symtab(struct MACH0_(obj_t) *bin, ut64 off);
bool parse_dysymtab(struct MACH0_(obj_t) *bin, ut64 off);
bool parse_thread(struct MACH0_(obj_t) *bin, struct load_command *lc, ut64 off, bool is_first_thread);
bool parse_dylib(struct MACH0_(obj_t) *bin, ut64 off);
bool parse_function_starts(struct MACH0_(obj_t) *bin, ut64 off);
void parse_signature(struct MACH0_(obj_t) *bin, ut64 off);