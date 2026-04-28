#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

typedef unsigned long long ut64;

typedef struct RzListIter RzListIter;
typedef struct RzList RzList;

#define rz_list_foreach(list, it, pos) \
    for (it = list->head; it && (pos = it->data); it = it->n)

struct RzListIter {
    void *data;
    RzListIter *n;
};

struct RzList {
    RzListIter *head;
    RzListIter *tail;
    size_t length;
};

typedef struct LuaProto {
    size_t name_size;
    const char *proto_name;
    ut64 offset;
    ut64 size;
    ut64 code_offset;
    ut64 code_size;
    ut64 const_offset;
    ut64 const_size;
    ut64 upvalue_offset;
    ut64 upvalue_size;
    ut64 inner_proto_offset;
    ut64 inner_proto_size;
    ut64 debug_offset;
    ut64 debug_size;
    RzList *local_var_info_entries;
    RzList *upvalue_entries;
    RzList *dbg_upvalue_entries;
    RzList *const_entries;
    RzList *proto_entries;
} LuaProto;

typedef struct LuacBinInfo {
    RzList *section_list;
    RzList *string_list;
    RzList *symbol_list;
} LuacBinInfo;

typedef struct LuaLocalVarEntry {
    const char *varname;
    ut64 offset;
    size_t varname_len;
} LuaLocalVarEntry;

typedef struct LuaDbgUpvalueEntry {
    const char *upvalue_name;
    ut64 offset;
    size_t name_len;
} LuaDbgUpvalueEntry;

typedef struct LuaConstEntry {
    int tag;
    const void *data;
    ut64 offset;
    size_t data_len;
} LuaConstEntry;

typedef struct LuaUpvalueEntry {
    ut64 offset;
} LuaUpvalueEntry;

#define LUA_VLNGSTR 4
#define LUA_VSHRSTR 5

#define RZ_FREE(x) free(x)
#define RZ_NEWS0(type, count) (type *)calloc(count, sizeof(type))

size_t rz_list_length(const RzList *list) {
    return list ? list->length : 0;
}

char *rz_str_new(const char *s);
char *rz_str_newf(const char *fmt, ...);
void luac_add_section(RzList *list, const char *name, ut64 offset, ut64 size, bool is_code);
void luac_add_string(RzList *list, const char *str, ut64 offset, size_t len);
void luac_add_symbol(RzList *list, const char *name, ut64 offset, size_t size, const char *type);
char *get_constant_symbol_name(const char *proto_name, const LuaConstEntry *entry);
const char *get_tag_string(int tag);
char *get_upvalue_symbol_name(const char *proto_name, const LuaUpvalueEntry *entry, const char *upvalue_name);