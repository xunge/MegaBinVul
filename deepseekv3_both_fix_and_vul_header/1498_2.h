#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef uint64_t ut64;

typedef struct RzListIter {
    void *data;
    struct RzListIter *n;
    struct RzListIter *p;
} RzListIter;

typedef struct RzList {
    RzListIter *head;
    RzListIter *tail;
    unsigned int length;
} RzList;

typedef struct LuaProto {
    char *proto_name;
    size_t name_size;
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
    char *varname;
    size_t varname_len;
    ut64 offset;
} LuaLocalVarEntry;

typedef struct LuaDbgUpvalueEntry {
    char *upvalue_name;
    size_t name_len;
    ut64 offset;
} LuaDbgUpvalueEntry;

typedef struct LuaConstEntry {
    int tag;
    void *data;
    size_t data_len;
    ut64 offset;
} LuaConstEntry;

typedef struct LuaUpvalueEntry {
    ut64 offset;
} LuaUpvalueEntry;

#define LUA_VLNGSTR 0
#define LUA_VSHRSTR 1

#define RZ_NEWS0(type, count) ((type *)calloc(count, sizeof(type)))
#define RZ_FREE(ptr) free(ptr)

void luac_add_section(RzList *list, char *name, ut64 offset, ut64 size, bool is_code);
void luac_add_string(RzList *list, char *str, ut64 offset, size_t len);
void luac_add_symbol(RzList *list, char *name, ut64 offset, size_t size, char *type);
char *rz_str_new(const char *s);
char *rz_str_newf(const char *fmt, ...);
char *get_constant_symbol_name(char *proto_name, LuaConstEntry *entry);
char *get_upvalue_symbol_name(char *proto_name, LuaUpvalueEntry *entry, char *upvalue_name);
char *get_tag_string(int tag);
size_t rz_list_length(RzList *list);

#define rz_list_foreach(list, it, pos) \
    for (it = list->head; it && (pos = it->data, 1); it = it->n)