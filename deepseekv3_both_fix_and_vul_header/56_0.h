#include <stdint.h>
#include <string.h>

typedef struct Dwarf_Attribute_s *Dwarf_Attribute;
typedef struct Dwarf_Debug_s *Dwarf_Debug;
typedef struct Dwarf_Die_s *Dwarf_Die;
typedef struct Dwarf_Error_s *Dwarf_Error;
typedef uint64_t Dwarf_Off;
typedef uint8_t Dwarf_Bool;
typedef uint8_t Dwarf_Sig8[8];

struct Dwarf_CU_Context_s {
    Dwarf_Bool cc_is_info;
};

struct Dwarf_Attribute_s {
    Dwarf_Debug ar_dbg;
    uint8_t *ar_debug_ptr;
    struct Dwarf_CU_Context_s *ar_cu_context;
};

struct Dwarf_Die_s {
    struct Dwarf_CU_Context_s *di_cu_context;
};

#define DW_DLV_OK 0