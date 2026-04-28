#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef uint8_t Dwarf_Small;
typedef uint16_t Dwarf_Half;
typedef uint32_t Dwarf_Unsigned;
typedef uint64_t Dwarf_Off;
typedef int Dwarf_Bool;
typedef unsigned char *Dwarf_Byte_Ptr;

typedef struct {
    Dwarf_Half ar_attribute_form;
    Dwarf_Byte_Ptr ar_debug_ptr;
} *Dwarf_Attribute;

typedef struct {
    Dwarf_Half cc_version_stamp;
    Dwarf_Bool cc_is_info;
    Dwarf_Unsigned cc_length;
    Dwarf_Unsigned cc_length_size;
    Dwarf_Unsigned cc_extension_size;
    Dwarf_Unsigned cc_debug_offset;
    Dwarf_Unsigned cc_address_size;
} *Dwarf_CU_Context;

typedef void *Dwarf_Debug;
typedef void *Dwarf_Error;

typedef struct {
    unsigned char sig[8];
} Dwarf_Sig8;

typedef struct dwarfstring {
    char *s;
    size_t len;
    size_t size;
} dwarfstring;

#define DWARF_HALF_SIZE 2
#define DWARF_32BIT_SIZE 4
#define DWARF_64BIT_SIZE 8
#define DW_CU_VERSION4 4

#define DW_DLV_OK 0
#define DW_DLV_ERROR 1
#define DW_DLV_NO_ENTRY 2

#define DW_FORM_ref1 1
#define DW_FORM_ref2 2
#define DW_FORM_ref4 3
#define DW_FORM_ref8 4
#define DW_FORM_ref_udata 5
#define DW_FORM_data4 6
#define DW_FORM_data8 7
#define DW_FORM_ref_addr 8
#define DW_FORM_sec_offset 9
#define DW_FORM_loclistx 10
#define DW_FORM_rnglistx 11
#define DW_FORM_GNU_ref_alt 12
#define DW_FORM_GNU_strp_alt 13
#define DW_FORM_strp_sup 14
#define DW_FORM_line_strp 15
#define DW_FORM_ref_sig8 16

#define DW_DLE_ATTR_FORM_OFFSET_BAD 1
#define DW_DLE_NOT_REF_FORM 2
#define DW_DLE_FORM_SEC_OFFSET_LENGTH_BAD 3
#define DW_DLE_REF_SIG8_NOT_HANDLED 4
#define DW_DLE_BAD_REF_FORM 5

#define TRUE 1

#define READ_UNALIGNED_CK(dbg, dest, type, src, size, error, end) \
    do { memcpy(&(dest), (src), (size)); } while(0)

#define DECODE_LEB128_UWORD_CK(ptr, dest, dbg, error, end) \
    do { (dest) = 0; } while(0)

int get_attr_dbg(Dwarf_Debug *dbg, Dwarf_CU_Context *cu_context, Dwarf_Attribute attr, Dwarf_Error *error);
Dwarf_Byte_Ptr _dwarf_calculate_info_section_end_ptr(Dwarf_CU_Context cu_context);
void _dwarf_error(Dwarf_Debug dbg, Dwarf_Error *error, int code);
void _dwarf_error_string(Dwarf_Debug dbg, Dwarf_Error *error, int code, const char *msg);
int find_sig8_target_as_global_offset(Dwarf_Attribute attr, Dwarf_Sig8 *sig8, Dwarf_Bool *is_info, Dwarf_Unsigned *offset, Dwarf_Error *error);
int dwarf_get_FORM_name(int formcode, const char **name);
void dwarfstring_constructor(dwarfstring *m);
void dwarfstring_append_printf_u(dwarfstring *m, const char *fmt, unsigned val);
void dwarfstring_append_printf_s(dwarfstring *m, const char *fmt, const char *str);
const char *dwarfstring_string(dwarfstring *m);
void dwarfstring_destructor(dwarfstring *m);