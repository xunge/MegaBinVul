#include <stdlib.h>
#include <stdint.h>

typedef uint64_t ut64;

typedef void (*RzListFree)(void*);

struct RzList;
typedef struct RzList RzList;

struct LuaProto {
    ut64 code_offset;
    ut64 code_skipped;
};

struct LuacBinInfo {
    RzList* entry_list;
    RzList* symbol_list;
    RzList* section_list;
    RzList* string_list;
};

typedef struct LuaProto LuaProto;
typedef struct LuacBinInfo LuacBinInfo;

enum {
    RZ_BIN_ENTRY_TYPE_PROGRAM
};

void RZ_LOG_ERROR(const char*);
#define RZ_NEW0(type) calloc(1, sizeof(type))
RzList* rz_list_newf(RzListFree);
void free_rz_addr(void*);
void rz_bin_symbol_free(void*);
void free_rz_section(void*);
void free_rz_string(void*);
void try_free_empty_list(RzList*);
void _luac_build_info(LuaProto*, LuacBinInfo*);
void luac_add_entry(RzList*, ut64, int);