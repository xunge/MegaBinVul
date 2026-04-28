#include <stddef.h>

typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef long FT_Long;
typedef int FT_Int;
typedef short FT_Short;
typedef int FT_Int32;
typedef unsigned long FT_ULong;
typedef long FT_Fixed;
typedef int FT_Bool;

struct FT_LibraryRec_;
typedef struct FT_LibraryRec_* FT_Library;

#define FT_LOCAL_DEF(x) x
#define FT_UNUSED(x) (void)(x)
#define FT_THROW(e) (-(e))
#define FT_Err_Ok 0
#define Invalid_Argument 1
#define FT_CHAR_BIT 8

typedef struct CFF_Parser_ {
    FT_Byte** top;
    FT_Byte** stack;
    FT_Byte* start;
    FT_Byte* limit;
    FT_Byte* cursor;
    FT_UInt stackSize;
    FT_Library library;
    FT_UInt object_code;
    void* object;
    FT_UInt num_designs;
    FT_UInt num_axes;
} *CFF_Parser;

typedef struct CFF_Decoder_ {
    FT_Fixed* stack;
    FT_Fixed* top;
    struct CFF_FontRec_* cff;
} CFF_Decoder;

typedef struct CFF_FontRec_ {
    struct {
        struct {
            FT_UInt num_designs;
            FT_UInt num_axes;
        } font_dict;
    } top_font;
} CFF_FontRec;

typedef enum {
    cff_kind_bool,
    cff_kind_string,
    cff_kind_num,
    cff_kind_fixed,
    cff_kind_fixed_thousand,
    cff_kind_delta,
    cff_kind_blend
} CFF_Field_Kind;

typedef struct CFF_Field_Handler_ {
    CFF_Field_Kind kind;
    FT_Int code;
    const char* id;
    size_t offset;
    size_t count_offset;
    FT_UInt array_max;
    size_t size;
    FT_Error (*reader)(CFF_Parser parser);
} CFF_Field_Handler;

extern const CFF_Field_Handler CFF_FIELD_HANDLERS_GET[];
extern FT_Error cff_parse_num(CFF_Parser parser, FT_Byte** data);
extern FT_Long cff_parse_fixed(CFF_Parser parser, FT_Byte** data);
extern FT_Long cff_parse_fixed_scaled(CFF_Parser parser, FT_Byte** data, int scale);
extern FT_Error cff_decoder_parse_charstrings(CFF_Decoder* decoder, FT_Byte* base, FT_ULong len, int is_t2);