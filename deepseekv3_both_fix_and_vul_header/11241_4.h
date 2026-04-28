#include <stdlib.h>

typedef struct dwg_object_ref dwg_object_ref;
typedef int BITCODE_BS;

typedef struct dwg_obj_block_control {
    BITCODE_BS num_entries;
    dwg_object_ref **block_headers;
} dwg_obj_block_control;

#define LOG_ERROR(fmt, ...)
#define __FUNCTION__ ""

#define Dwg_Object_Ref dwg_object_ref