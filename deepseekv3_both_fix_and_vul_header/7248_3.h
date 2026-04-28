#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define PE_NAME_LENGTH 255
#define UT16_MAX 0xFFFF
#define PE_DWORD_MAX 0xFFFFFFFF
#define ILT_MASK1 0x80000000
#define ILT_MASK2 0x7FFFFFFF
#define R2_SDB_FORMAT "sdb"
#define PFMT64x "llx"

typedef uint32_t PE_DWord;
typedef uint16_t PE_Word;
typedef uint64_t ut64;
typedef uint8_t ut8;

struct r_bin_pe_import_t {
    char name[PE_NAME_LENGTH + 1];
    char libname[PE_NAME_LENGTH + 1];
    ut64 vaddr;
    ut64 paddr;
    PE_Word hint;
    PE_Word ordinal;
    int last;
};

typedef struct RBinPEObj {
    ut64 size;
    void* b;
} RBinPEObj;

typedef struct Sdb Sdb;

#define PE_(x) PE_##x
#define PE_va2pa(pe, va) PE_va2pa_impl(pe, va)
#define R_BUF_READ_PE_DWORD_AT(buf, offset) 0
#define R_FREE(x) free(x)
#define R_JOIN_4_PATHS(a,b,c,d) a b c d

static int bin_pe_rva_to_va(RBinPEObj* pe, PE_DWord rva) { return 0; }
static PE_DWord PE_va2pa_impl(RBinPEObj* pe, PE_DWord va) { return 0; }
static void pe_printf(const char* fmt, ...) {}
static void r_str_case(char* str, int to_lower) {}
static char* r_str_newf(const char* fmt, ...) { return NULL; }
static int r_file_exists(const char* file) { return 0; }
static Sdb* sdb_new(void* a, const char* b, int c) { return NULL; }
static void sdb_free(Sdb* db) {}
static char* resolveModuleOrdinal(Sdb* db, const char* dll, int ordinal) { return NULL; }
static char* r_sys_prefix(const char* p) { return NULL; }
static void r_sys_perror(const char* msg) {}
static void eprintf(const char* fmt, ...) {}
static int r_buf_read_le16_at(void* buf, ut64 offset) { return 0; }
static int r_buf_read_at(void* buf, ut64 offset, ut8* data, int len) { return 0; }