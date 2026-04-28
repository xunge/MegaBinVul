#include <stddef.h>
#include <string.h>

typedef unsigned char Dwarf_Small;
typedef unsigned long Dwarf_Unsigned;
typedef long Dwarf_Signed;
typedef unsigned long Dwarf_Off;
typedef int Dwarf_Bool;
typedef struct Dwarf_Debug_s *Dwarf_Debug;
typedef struct Dwarf_Global_s *Dwarf_Global;
typedef struct Dwarf_Error_s *Dwarf_Error;
typedef struct Dwarf_Global_Context_s *Dwarf_Global_Context;
typedef struct Dwarf_Chain_s *Dwarf_Chain;

#define FALSE 0
#define TRUE 1
#define DW_DLE_DBG_NULL 1
#define DW_DLE_ALLOC_FAIL 2
#define DW_DLE_STRING_OFF_END_PUBNAMES_LIKE 3
#define DW_DLV_ERROR -1
#define DW_DLV_OK 0
#define DW_DLV_NO_ENTRY 1
#define DW_PUBNAMES_VERSION2 2
#define DWARF_32BIT_SIZE 4
#define DWARF_HALF_SIZE 2
#define DW_DLA_LIST 1
#define DW_DLA_CHAIN 2

struct Dwarf_Debug_s {
    unsigned de_magic;
    struct {
        Dwarf_Small *dss_data;
    } de_debug_info;
    Dwarf_Bool de_return_empty_pubnames;
};

struct Dwarf_Global_Context_s {
    int pu_alloc_type;
    int pu_length_size;
    Dwarf_Unsigned pu_length;
    int pu_extension_size;
    Dwarf_Debug pu_dbg;
    Dwarf_Off pu_pub_offset;
    Dwarf_Small *pu_pub_entries_end_ptr;
    Dwarf_Unsigned pu_version;
    Dwarf_Off pu_offset_of_cu_header;
    Dwarf_Unsigned pu_info_length;
};

struct Dwarf_Chain_s {
    Dwarf_Global ch_item;
    Dwarf_Chain ch_next;
};

struct dwarfstring_s {
    char *s_data;
    size_t s_size;
    size_t s_avail;
};
typedef struct dwarfstring_s *dwarfstring;

#define DBG_IS_VALID 0x12345678

void _dwarf_error_string(Dwarf_Debug dbg, Dwarf_Error *error, int code, const char *msg);
void _dwarf_error(Dwarf_Debug dbg, Dwarf_Error *error, int code);
int _dwarf_load_debug_info(Dwarf_Debug dbg, Dwarf_Error *error);
void * _dwarf_get_alloc(Dwarf_Debug dbg, int type, size_t size);
void dwarf_dealloc(Dwarf_Debug dbg, void *ptr, int type);
void dealloc_globals_chain(Dwarf_Debug dbg, Dwarf_Chain chain);
void pubnames_error_length(Dwarf_Debug dbg, Dwarf_Error *error, int size, const char *secname, const char *msg);
int _dwarf_read_area_length_ck_wrapper(Dwarf_Debug dbg, Dwarf_Unsigned *len, Dwarf_Small **ptr, int *len_size, int *ext_size, Dwarf_Unsigned sec_len, Dwarf_Small *sec_end, Dwarf_Error *error);
int _dwarf_read_unaligned_ck_wrapper(Dwarf_Debug dbg, void *out, Dwarf_Small *in, int size, Dwarf_Small *end, Dwarf_Error *error);
int _dwarf_check_string_valid(Dwarf_Debug dbg, Dwarf_Small *start, Dwarf_Small *ptr, Dwarf_Small *end, int err_code, Dwarf_Error *error);
int _dwarf_make_global_add_to_chain(Dwarf_Debug dbg, int alloc_type, Dwarf_Global_Context context, Dwarf_Off offset, unsigned char *name, Dwarf_Unsigned *count, Dwarf_Bool *on_list, Dwarf_Chain **last_chain, Dwarf_Error *error);
void FIX_UP_OFFSET_IRIX_BUG(Dwarf_Debug dbg, Dwarf_Off offset, const char *msg);
void dwarfstring_constructor(dwarfstring *m);
void dwarfstring_append_printf_u(dwarfstring *m, const char *fmt, Dwarf_Unsigned val);
void dwarfstring_append_printf_s(dwarfstring *m, const char *fmt, const char *val);
char *dwarfstring_string(dwarfstring *m);
void dwarfstring_destructor(dwarfstring *m);